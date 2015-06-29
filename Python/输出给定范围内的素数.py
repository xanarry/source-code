import math
n = int(input().strip())#数据量
def isPrime(x):#exam prime number
    if x < 2:
        return False;
    else:
        for i in range(2, int(math.sqrt(x)) + 1):
            if x % i == 0:
                return False
    return True

for x in range(n):#deal each input
    a, b = map(int, input().strip().split())#input start and destination
    for i in range(a, b + 1):
        if isPrime(i):
            print(i)#out put prime
    print()
