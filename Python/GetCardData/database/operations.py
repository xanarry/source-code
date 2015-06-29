import mysql.connector
from mysql.connector import errorcode

class mysql_task:
    def __init__(self):
        self.cursor = None
        self.cnx = None

    def connect(self, puser, ppassword, phost, pdatabase = None):
        '''连接数据库'''
        try:
            self.cnx = mysql.connector.connect(user = puser, password = ppassword, host = phost, database = pdatabase)
            self.cursor = self.cnx.cursor()
            return True
        except mysql.connector.Error as err:  
            if err.errno == errorcode.ER_ACCESS_DENIED_ERROR:
                print("请检查数据库账户不存在或者密码错误")
            elif err.errno == errorcode.ER_BAD_DB_ERROR:
                print("数据库不存在")
            else:
                print(err)
            print(err)
            return None
        else:
            print("数据库连接成功")
            
    def do_query(self, sql):
        '''执行MySQL语句'''
        try:
            self.cursor.execute(sql)
            self.cnx.commit()
            return list(x for x in self.cursor)
        except Exception as e:
            print("错误:", e)
            return None

    def close_connect(self):
        '''关键连接'''
        self.cnx.close()
        self.cursor.close()
        