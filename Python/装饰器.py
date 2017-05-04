def print_list10():#定义函数输出0到9的列表
    print(list(x for x in range(10)))

def decorator(func):
    def execute():
        print("start execute:", func.__name__)
        func()
        print("finish execute:", func.__name__)
    return execute


f1 = decorator(print_list10)
f1()

@decorator     #@后面的关键词是前面定义的函数,并且该函数至少要有个的参数和返回函数
def output():
    print("1234567890")

output()

print("-----------------------------------\n")

#装饰器函数带参数装饰器
def deco(add):
    def output(a, b):
        print("add", a, "and", b)
        return add(a, b)
    return output

def add(a, b):
    return a + b

print(add(9, 8))
add = deco(add)
print(add(9, 8))

print("-----------------------------------\n")

#使用可变参数创建一个通用装饰器
def universdeco(func):
    def wraper(*args, **kwargs):
        print("in wraper")
        print("first args:", list(args))
        print("second kwargs:", list(kwargs))
        func(*args, **kwargs)
    return wraper

@universdeco
def showargs(a, b):
    print("in func")
    print(a, b)

showargs(123, 234)

print("\n--------------------------------")
#使用装饰器提供缓存提高递归函数的效率,
from functools import wraps
def cache(func):
    caches = {}

    @wraps(func)
    def wrap(*args):
        if args not in caches:
            caches[args] = func(*args)

        return caches[args]
    return wrap

@cache
def fib_cache(n):
    assert n > 0, 'invalid n'
    if n < 3:
        return 1
    else:
        return fib_cache(n - 1) + fib_cache(n - 2)

print(fib_cache(4))

print("\n--------------------------------")
#使用装饰器计算一个函数的执行时间
def deco1(func):
    import time
    def wraper(n):
        t = time.clock()
        res = func(n)
        print(func.__name__, "time consume:", time.clock() - t, "s")
        return res
    return wraper

@deco1
def sums(n):
    return sum(x for x in range(n))
print(sums(10000000))
        

'''
@deco1
def func():
    pass
以上的写法相当于
func = deco1(func)
'''
