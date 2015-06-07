from functools import reduce
def multiply(a, b):
    a = list(map(lambda x : int(x), a.strip()))
    b = list(map(lambda x : int(x), b.strip()))
    c = list(map(lambda x : 0, ("0" + str(a) + str(b)).strip()))
    index = len(c) - 1;
    for i in range(len(a) - 1, -1, -1):
        pos = 0
        for j in range(len(b) - 1, -1, -1):
            temp = a[i] * b[j] + c[index - pos]
            c[index - pos] = temp % 10
            c[index - pos - 1] += temp // 10
            pos += 1
        index -= 1
    return int(reduce(lambda x, y : str(x) + str(y), c))

a = input("input a: ")
b = input("input b: ")
print(multiply(a, b))