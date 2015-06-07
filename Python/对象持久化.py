#读写单个对象到文件
computer = {}
computer["mark"] = "thikpad"
computer["price"] = 4500
computer["memery"] = "4G"
computer["HDD_size"] = "500G"
print(computer)

print("write dict to file:")
import pickle
f = open("computer", "wb")
pickle.dump(computer, f)
print("write successful")
print("\n------------------")
print("reload computer from file")
f = open("computer", "rb")
computer = pickle.load(f)
print(computer)
print("over")

#写入类定义到文件
print("写入类定义到文件")
class book:
    def __init__(self, n, p):
        self.name = n
        self.price = p
    def __str__(self):
        return "name: " + self.name + ", price: " + str(self.price)

print("写入类")
f = open("books", "wb")
pickle.dump(book, f)
print("读取类")
f = open("books", "rb")
book = pickle.load(f)
print(book)
print("以下开始使用类")

print("\n读写多个对象到文件")
#读写多个对象到文件
import random
names = ["asdf", "keywh3", "jxcre", "9snfg", "89uhtf", "kuewf"]
f = open("books", "wb")
print("开始生成并写入文件")
for x in range(10):
    b = book(random.choice(names), random.randint(50, 100))
    pickle.dump(b, f)\

print("从文件中加载对象")
f = open("books", "rb")
try:
    while f:
        b  = pickle.load(f)
        print(b)
except:
    print("操作完毕")
