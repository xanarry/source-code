#闭包可以理解为一个将一系列相关的环境变量与一个函数一同打包返回
#然后后面再使用函数的时候所附带的环境变量则跟随着函数起作用
def addbase(n):
    def add(x):
        return x + n
    return add

add = addbase(10)#手动设定闭包中的环境变量为10
print(add(12))#输出结果为"10+12"=22

del addbase#删除addbase的定义
print(add(100))#再次执行,返回110
