import random
def merge(a, b):
    i, j = 0, 0
    c = []
    while i < len(a) and j < len(b):
        if a[i] < b[j]:
            c.append(a[i])
            i += 1
        else:
            c.append(b[j])
            j += 1
    c += (a[i : ] if i < len(a) else (b[j : ] if j < len(b) else None))
    return c

a = sorted(random.randint(1, 10) for i in range(5))
print(a)
b = sorted(random.randint(1, 10) for i in range(10))
print(b)
print(merge(a, b))

