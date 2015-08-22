import stunum_generator
import database
import re
import time
from network import scraper
from database import table_desc
from database import config
from database import operations

def log(f, stu_num, stu_name, data_set):
    '''本函数用于屏幕输出状态和写入日志到scraplog.txt文件'''
    localtime = time.localtime(time.time())
    str_time = "%04d-%02d-%02d %02d:%02d:%02d" % (localtime[0], localtime[1], localtime[3], localtime[3], localtime[4], localtime[5])
    res = ""

    if stu_name != None:#姓名只有登录成功后才能获取,如果没有得到姓名,说明登录失败
        overview = None
        if data_set != None:
            g = lambda x: x[2] 
            # 分别获取早操, 俱乐部, 身体拓展, 自主学习的有效次数
            overview = (list(map(g, data_set["zc"])).count("有效"), list(map(g, data_set["jlb"])).count("有效"), list(map(g, data_set["sttz"])).count("有效"), list(map(g, data_set["zzxx"])).count("有效"))
        
        for x in range(4 - len(stu_name)): #将短姓名统一拼接空格为四个汉字的长度
            stu_name += "  "
        #将各类型的刷卡数据添加到字符串中
        state = ("内容残缺, 未写入" if overview == None else "早操:%2d, 俱乐部:%2d, 身体拓展:%2d, 自主学习:%2d" % overview)
        res = "visit: {0} {1} state: ".format(stu_num, stu_name) + state;
    else: #登录失败
         res = "visit: " + stu_num + " 学号不存在或者密码错误"
    f.write(str_time + " " + res + "\n")#写入到log日志文件, 日志文件中有记录时间
    f.flush()#每条记录立即写入到文件
    print(res)#输出到屏幕的内容不含时间

def init_db(): 
    '''初始化数据库, 创建数据库, 创建所需要的数据表, 然后返回操作句柄'''
    drop_db = "drop database if exists " + config.params["database"]
    creat_db = "create database " + config.params["database"]
    change_db = "use " + config.params["database"]
    mysql_task = operations.mysql_task() #构建操作数据库的对象
    #连接数据库(没有选择数据库)并检查是否连接成功
    if mysql_task.connect(config.params["user"], config.params["password"], config.params["host"]) == True:
        #如果连接成功
        mysql_task.do_query(drop_db)#删除重复的数据库
        mysql_task.do_query(creat_db)#创建数据库
        mysql_task.do_query(change_db)#选定当前数据库
        mysql_task.do_query(table_desc.tables["student"])#创建student表,存储学号, 姓名, 学号为主键
        mysql_task.do_query(table_desc.tables["zc"])#创建zc表, 存储早操的信息
        mysql_task.do_query(table_desc.tables["jlb"])#存储俱乐部的信息
        mysql_task.do_query(table_desc.tables["sttz"])#存储身体素质拓展信息
        mysql_task.do_query(table_desc.tables["zzxx"])#存储自主学习信息
        mysql_task.do_query(table_desc.tables["overview"])#存储各类刷卡次数有效次数的信息
        mysql_task.close_connect()#关闭当前连接

        #重新创建新的选定了数据库的连接, 并返回用于后面的操作
        mysql_task = operations.mysql_task()
        mysql_task.connect(config.params["user"], config.params["password"], config.params["host"], config.params["database"])
        return mysql_task
    else:
        return None


def write_to_db(mysql_handler, stu_num, stu_name, card_records):
    if card_records != None and mysql_handler != None:
        #写入学生信息的到数据库
        insert_student = "insert into student (stu_num, stu_name) values('%s', '%s')" % (stu_num, stu_name) 
        mysql_handler.do_query(insert_student)

        #写入刷卡数据到数据库
        insert_record = lambda table, stu_num, record : "insert into %s (stu_num, date, time, is_valid) values('%s', '%s', '%s', '%s')" % (table, stu_num, record[0], record[1], record[2])
        overview = {}
        for x in card_records: #遍历刷卡类型
            valid = 0 #遍历刷卡的有效次数
            for y in card_records[x]: #遍历该类型刷卡的所有数据
                if y[2] == "有效":
                    valid += 1
                mysql_handler.do_query(insert_record(x, stu_num, y)) #写入记录
            overview[x] = (valid, len(card_records[x]) - valid)

        #写入个人的刷卡概况, 即各类刷卡的有效次数
        insert_overview = "insert into overview (stu_num, zc_valid, jlb_valid, sttz_valid, zzxx_valid, zc_not_valid, jlb_not_valid, sttz_not_valid, zzxx_not_valid) values('%s', %d, %d, %d, %d, %d, %d, %d ,%d)" % (stu_num, overview["zc"][0], overview["jlb"][0], overview["sttz"][0], overview["zzxx"][0], overview["zc"][1], overview["jlb"][1], overview["sttz"][1], overview["zzxx"][1])
        mysql_handler.do_query(insert_overview)

def get_detail(opener):
    '''调用函数一次获取所有刷卡数据'''
    return scraper.scrap(opener).get_all()


#----------------------------------------程序入口-------------------------------------------#
print("初始化数据库")
mysql_handler = init_db()
#创建日志文件
f = open("scraplog.txt", "w")

#年份的范围
start_year = 2013
end_year = 2014
#专业代码范围
start_major = 21
end_major = 80
#编号范围
start_num = 0
end_num = 999

#创建可以迭代的生成器
stunum = stunum_generator.generator(start_year, end_year, start_major, end_major, start_num, end_num)

#遍历每个学号, 访问使用默认密码的刷卡数据
try:
    while True:
        account = stunum.__next__() #迭代学号
        password = account #学号和密码一样
        user_name = None #保存用户名
        #登陆网站, 返回一个元组, 分别保存可以继续访问跳转连接的对象, 和用户姓名
        result = scraper.login(account, password).get_opener()
        if result:
            opener = result[0] #获取用于网络访问的对象
            user_name = result[1]; #获取学生姓名
            data_set = get_detail(opener) #获取所有刷卡数据
            log(f, account, user_name, data_set) #记录日志
            write_to_db(mysql_handler, account, user_name, data_set) #写入MySQL数据库
        else:
            log(f, account, None, None)
except Exception as e:
    mysql_handler.close_connect()
    f.write("任务完成")
    f.close()
    print(e)  
#--------------------------------------程序结束---------------------------------------#
