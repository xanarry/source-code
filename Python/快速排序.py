import random
import sys
sys.setrecursionlimit(100000)

swap = lambda x, y : (y, x)
def qsort(a, l, r):
    if l >= r:
        return
    pavit, i, j = a[l], l, r
    while i != j:
        while i < j and a[j] >= pavit:
            j -= 1
        while i < j and a[i] <= pavit:
            i += 1
        a[i], a[j] = swap(a[i], a[j])

    a[l], a[i] = swap(a[l], a[i])
    qsort(a, l, i - 1)
    qsort(a, i + 1, r)

a = list(random.randint(0, 10) for x in range(10000))
qsort(a, 0, len(a) - 1)
print(a)