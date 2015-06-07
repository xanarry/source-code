def fac(n):
    return 1 if n <= 0 else n * fac(n - 1)
print(fac(10))