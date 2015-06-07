import random

def merge(a, b):
    '''合并两个有序的列表'''
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

def merge_sort(a, l, r):
    mid = (l + r) // 2
    #首先不断分段,知道两端元素都是有序的
    if l < mid:
        merge_sort(a, l, mid)
        merge_sort(a, mid, r)
    #然后合并两个有序序列实现排序
    a[l : r] = merge(a[l : mid], a[mid: r])

a = list(random.randint(10, 50) for x in range(100))
print("original list:", a)
merge_sort(a, 0, len(a))
print("sorted  list :", a)
