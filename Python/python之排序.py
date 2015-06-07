strs = ["five", "six", "seven", "eight", "nine", "ten", "zero", "one", "two", "three", "four"]
nums = [10, 3, 4, 1, 2, 9, 6, 5, 8, 7, 0]

#1手写排序算法
tnums = nums
for i in range(len(tnums) - 1):
    for j in range(len(tnums) - 1 - i):
        if tnums[j] > tnums[j + 1]:
            tmp = tnums[j]
            tnums[j] = tnums[j + 1]
            tnums[j + 1] = tmp
print(tnums)

#使用sort函数,三个参数sort(*, key=None, reverse=None) 
#默认数字按大小,字符串按字典序升序排序,对于多属性对象,也可以指定关键字排序,后面说到
tnums = nums
tnums.sort()
print(tnums)
#降序排序
tnums.sort(reverse = True)
print(tnums)

#使用内置函数sorted,返回一个有序序列
tnums = sorted(nums)
print(tnums)
#降序排序
tnums = sorted(nums, reverse = True)
print(tnums)

'''
sort函数与sorted的函数的区别是sort仅仅是list中的方法,其他地方用不了
而sorted函数是可迭代序列的通用排序函数,任何序列都可以使用sorted函数
'''

#对字典进行排序,切记不要奢望python能像c++一样企图得到一个有序的dict,因为python的特点,这是不可能的
#也就仅仅只能提取键值对后保存到一个有序的list中,
enum = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"]
nnum = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
#首先使用上面两个列表生成字典
sdict = dict(zip(nnum, enum))

#按原始顺序输出字典
for item in sdict.items():
    print(item[0], item[1])
print("------------------")

#使用sorted函数对字典按value排序
tdict = sorted(sdict.items(), key = lambda x : x[1])
#按value值排序输出
for item in tdict:
    print(item[0], item[1])
print("-----------------")

#对dict按key降序排序
tdict = sorted(sdict.items(), key = lambda x: x[0], reverse = True)
for item in tdict:
    print(item[0], item[1])
print("-----------------")

#按对象的属性排序
class book:
    def __init__(self, name, price):
        self.name = name
        self.price = price
    def __str__(self):
        return "name: " + str(self.name) + ", price: " + str(self.price)

#生成对象列表
name = ["ed", "dfw", "zert", "gwert", "rgsd", "hkjhi", "ydfg", "indf", "kjsdf", "kenfs"]
price = [123, 435, 12, 56, 23, 12, 674, 123, 3452, 979]
books = list(book(x, y) for x, y in zip(name, price))

for x in books:
    print(x)
print("-------------------")

#使用sorted按书名排序
sbooks = sorted(books, key = lambda x : x.name)
for x in sbooks:
    print(x)
print("------------------")


#按书价排序
tbooks = books;
tbooks.sort(key = lambda x: x.price)
for x in tbooks:
    print(x)
print("-------------------")

#自定义排序,首先按价格排序,如果价格相同,那么再按书名字典序排序
sbooks = sorted(books, key = lambda x : (x.price, x.name))
for x in sbooks:
    print(x)
print("-------------------")

#自定义排序,首先按姓名长度,如果长度相同,那么再按价格降序排序
sbooks = sorted(books, key = lambda x : (len(x.name), -x.price))#对某一项降序排序加一个负号即可
for x in sbooks:
    print(x)
print("-------------------")

#使用attrgetter(key1, key2...)先按name排序,相同按price排序
import operator
sbooks = sorted(books, key = operator.attrgetter("name", "price"))
for x in sbooks:
    print(x)
print("-------------------")