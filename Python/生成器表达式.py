s = sum(i * i for i in range(10))
print(s)

a = [12, 45, 23, 546, 52]
b = [21, 43, 56, 673, 59]
for x, y in zip(a, b):
    print(str(x) + "+" + str(y) + "=" + str(x + y))

c = list(x - y for x, y in zip(a, b))
print(c)

s = "asdfhjasdfgqwyeasnbdglasfdasdfjyqoiwu"
print(list(s))
unique_char = set(list(s))
print(unique_char)

unique_char = set(char for char in s)
print(unique_char)

matrix = [ [1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16] ]
for i in matrix:
    for j in i:
        print("%2d " % j, end = "")
    print()

h = sum(x for r in matrix for x in r)
print("sum of above matrix = %d" % h)


#构造反向字符串作用等同于string[::-1]
string = "qwertyuiop"
rstring = list(string[i] for i in range(len(string) - 1, -1, -1))
print(rstring)
print(list(string[::-1]))