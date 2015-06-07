from functools import reduce
def cmpare(a, b):
    if (len(a) != len(b)):
        return len(a) - len(b)
    else:
        for i in range(len(a)):
            if a[i] != b[i]:
                return a[i] - b[i]
    return 0

def minus(a, b):
    optr = "+";
    if (cmpare(a, b) < 0):
        optr = '-'#如果减数大于被减数,设置符号为负号
        temp = a#并且交换两个数,保证始终用大数减小数
        a = b
        b = temp
        
    a = list(map(lambda x : int(x), ("0" + str(a)).strip()))
    b = list(map(lambda x : int(x), ("0" + str(b)).strip()))

    if len(a) > len(b):
        for x in range(len(a) - len(b)):
            b.insert(0, 0)
    else:
        for x in range(len(b) - len(a)):
            a.insert(0, 0)
    
    for i in range(len(a) - 1, 0, -1):
        if (a[i] >= b[i]):
            a[i] -= b[i]
        else:
            a[i] = a[i] + 10 - b[i]
            a[i - 1] -= 1
    return int(optr + reduce(lambda x, y : str(x) + str(y), a))

a = input("input a: ")
b = input("input b: ")
print(minus(a, b))