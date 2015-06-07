from functools import reduce#导入reduce用于将整数列表中的内容转换为字符串
def add(a, b):
    if len(a) > len(b):#将输入的数字左端补齐为同样的长度
        b = b.zfill(len(a) - len(b) + 1)
    else:
        a = a.zfill(len(b) - len(a) + 1)
        
    a = list(map(lambda x : int(x), ("0" + str(a)).strip()))
    b = list(map(lambda x : int(x), ("0" + str(b)).strip()))

    for i in range(len(a) - 1, 0, -1):
        temp = a[i] + b[i];
        a[i - 1] += temp // 10
        a[i] = temp % 10
    return int(reduce(lambda x, y : str(x) + str(y), a))

a, b = input("input a: "), input("input b: ")
print(add(a, b))