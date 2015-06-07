import mysql.connector
from mysql.connector import errorcode

cnx = None
try:
    cnx = mysql.connector.connect(user = "root", password = "admin", host = "127.0.0.1", database = "card_data_2015")
except mysql.connector.Error as err:  
    if err.errno == errorcode.ER_ACCESS_DENIED_ERROR:
        print("请检查数据库账户不存在或者密码错误")
    elif err.errno == errorcode.ER_BAD_DB_ERROR:
        print("数据库不存在")
    else:
        print(err)
    print(err)
else:
    print("数据库连接成功")

cursor = cnx.cursor()

sql = "select * from student"
cursor.execute(sql)
for x in cursor:
    print(x)

print("sdafasdfasdfasdf")

add_s = ("INSERT INTO student "
              "(stu_num, stu_name) "
              "VALUES (%(num)s, %(name)s)")
data_s = {
  'num': '201302000',
  'name': 'aa',
}
cursor.execute(add_s, data_s)


sql = "insert into student (stu_num, stu_name) values('2013023001', 'bb')"
cursor.execute(sql)


sql = "insert into student (stu_num, stu_name) values('2013023002', 'cc')"
cursor.execute(sql)

sql = "insert into student (stu_num, stu_name) values('2013023003', 'dd')"
cursor.execute(sql)

sql = "insert into student (stu_num, stu_name) values('2013023004', 'ee')"
cursor.execute(sql)
cnx.commit()
sql = "select * from student"
cursor.execute(sql)
for x in cursor:
    print(x)
