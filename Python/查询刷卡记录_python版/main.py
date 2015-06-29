'''
author: xanarry
date: 2015-5-30
email: xanarry@163.com
note: 本文件为查询刷卡记录的入口程序
'''
import re
import time
from network import scraper

def output(record, record_name = ""):
    '''record是某一刷卡记录是数据列表, 其中包含三个元组, 
    第一个元组是每条记录日期, 第二个元组是每条记录的时间, 
    第三个元组是每次刷卡是否有效, record_name标记当前输出
    的是什么刷卡记录'''
    if record:
        print("%s\t%s\t%s" % ("有效性", "刷卡日期", "刷卡时间"))
        print("--------------------------------------")
        valid_time = 0
        for x in record:
            if len(x) == 3:
                print("%s\t%s\t%s" % (x[2], x[0], (x[1] if x[1][-1] != "-" else x[1] + "########")))
                if x[2] == "有效":
                    valid_time += 1
        print("--------------------------------------")
        print("\"" + record_name + "\" 有效:", valid_time, "次, 无效:", len(record) - valid_time, "次 记录总数:", len(record))
    else:
        print("未发现\"" + record_name + "\"有效记录!")

def get_detail(opener):
    '''将opener传递给scraper对象,然后依次调用每个函数查询早操, 俱乐部, 自主学习, 身体素质的刷卡记录'''
    getinfo = scraper.scrap(opener)
    print("\n\"早操\"信息...")
    output(getinfo.get_zc(), "早操")
    
    print("\n\"身体素质拓展\"信息...")
    output(getinfo.get_sttz(), "身体素质拓展")
        
    print("\n\"自主学习\"信息...")
    output(getinfo.get_zzxx(), "自主学习")
    
    print("\n\"俱乐部\"信息...")
    output(getinfo.get_jlb(), "俱乐部")

#account = input("输入学号: ").strip()
#password = input("输入密码: ").strip()
account = "2013023058"
password = account;
user_name = None
print("正在登陆...")
result = scraper.login(account, password).get_opener()
if result:
    opener = result[0]
    user_name = result[1];
    print("hello!", user_name, "登陆成功")
    get_detail(opener)
   
while input("回车键退出..."):
    pass