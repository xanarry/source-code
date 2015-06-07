class Book:
    def __init__(self, name, price):
        self.name = name
        self.price = price

    def __str__(self):
        return "name: " + str(self.name) + ", price: " + str(self.price)

#重载比较运算符号
    def __eq__(x, y):#x == y
        if x.price == y.price:
            return True
        return False

    def __ne__(x, y):#x != y
        if x.price != y.price:
            return True
        return False

    def __lt__(x, y):#x < y
        if x.price < y.price:
            return True
        return False

    def __le__(x, y):#x <= y
        if x.price <= y.price:
            return True
        return False

    def __gt__(x, y):#x > y
        if x.price > y.price:
            return True
        return False

    def __ge__(x, y):#x >= y
        if x.price >= y.price:
            return True
        return False

name = ["ed", "dfw", "wert", "gwert", "rgsd", "fkjhi", "ydfg", "indf", "kjsdf", "kenfs"]
price = [123, 435, 12, 56, 23, 463, 674, 1326, 3452, 979]

books = list(Book(x, y) for x, y in zip(name, price))

print("unorder seq:")
for x in books:
    print(x)

print('sorted seq:')
books.sort()
for x in books:
    print(x)