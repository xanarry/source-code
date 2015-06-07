def tofind(string):
    pattern = "aeiouAEOIU"
    for i in range(len(string)):
        if string[i] in pattern:
            yield i

g = tofind(input("input a string: "))
print(list(g))#生成器仅仅第一次迭代有效,因为只保留函数的信息一次,迭代完之后就没有了
print(list(g))