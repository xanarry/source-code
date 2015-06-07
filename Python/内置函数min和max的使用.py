seq = [34, 123, 43, 235, 6, 345, 78]
print(max(seq))
print(min(seq))

class book:
    def __init__(self, name, price):
        self.name = name
        self.price = price
    def __str__(self):
        return "name: " + str(self.name) + ", price: " + str(self.price);

books = []
books.append(book("c", 23))
books.append(book("ccc", 86))
books.append(book("java", 57))

#找到价格最高的
print(max(books, key = lambda x : x.price))
#找到名字最长的
print(max(books, key = lambda x : len(x.name)))
#找到字典序最小的
print(min(books, key = lambda x : x.name))
