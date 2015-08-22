class Stack():
    '''using a single linked list with a head node to implement a Stack, the key area of head node
        save the size of this Stack'''
    class Node():
        '''inside class to provide linked list node'''
        def __init__(self, key = None, next = None):
            self.key = key
            self.next = next

    def __init__(self):
        self.__head = self.Node()#declear the head of this list
        self.__head.key = 0;

    def push(self, key):
        '''push one key into Stack: insert one key at the front of the list after head node'''
        newOne = self.Node(key, self.__head.next)
        self.__head.next = newOne
        self.__head.key += 1

    def pop(self):
        '''pop one key off Stack: delete one key at the front of the list after head node'''
        temp = self.__head.next
        self.__head.next = temp.next
        del(temp)
        self.__head.key -= 1

    def size(self):
        return self.__head.key

    def empty(self):
        return True if self.__head.key <= 0 else False

    def clear(self):
        self.__head.key = 0;
        temp = self.__head.next
        while temp:
            self.__head.next = temp.next
            del(temp)
            temp = self.__head.next

    def genIter(self):
        '''generate a iteratable generater'''
        temp = self.__head.next
        while temp:
            yield temp.key
            temp = temp.next
#######################################

def show():
    print(list(s.genIter()))

s = Stack()
for x in range(10):
    s.push(x); print(s.size()); show()

print(s.empty())

for x in range(10):
    s.pop(); print(s.size()); show()

print(s.empty());

for x in range(100):
    s.push(x)
show()
s.clear()
show()
print(s.size())
print(s.empty())

