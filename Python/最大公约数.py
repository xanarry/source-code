def gcd1(a, b):
    while b != 0:
        t = a % b
        a = b
        b = t
    return a

def gcd2(a, b):
    return a if b == 0 else gcd2(b, a % b)

while True:

    a, b = map(int, input().strip().split())
    print("gcd1: " + str(gcd1(a, b)) + " gcd2: " + str(gcd2(a, b)))
