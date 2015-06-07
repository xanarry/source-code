import sys
import random
sys.setrecursionlimit(10000)

def qsort(a, l, r):
    if l >= r:
        return
    p, i, j = a[l], l, r
    while i != j:
        while i < j and a[j] >= p:
            j -= 1
        if i < j:
            a[i] = a[j]
        while i < j and a[i] <= p:
            i += 1
        if i < j:
            a[j] = a[i]
            
    a[i] = p
    qsort(a, l, i - 1)
    qsort(a, i + 1, r)

a = list(random.randint(0, 10) for x in range(10000))
qsort(a, 0, len(a) - 1)
print(a)