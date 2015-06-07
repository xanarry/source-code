#常规函数
def add(x, y):
    return x + y


#缺省参数函数,即带有默认参数
def output(name = "empty", age = 21, sex = 'F'):
    print("name = " + str(name))
    print("age = " + str(age))
    print("sex = " + str(sex))

#不定长参数函数
def sumof(*arglist):
    sum = 0
    for x in arglist:
        sum += x
    return sum;

print(add(12, 23))
#使用默认带参数的函数要指定值到具体的参数,默认从左向右给参数赋值
print(output(name = "xanarry", sex = "M"))
print(sumof(12, 123, 43532))

#python中所有函数的传值都是引用,如果不需要修改原值,传递一个副本即可