class Queue():
    '''using double-linked list to implement a queue'''
    class __Node():
        '''inner class as double-linked list node'''
        def __init__(self, key = None, pre = None, next = None):
            self.key = key
            self.pre = pre
            self.next = next

    def __init__(self):
        self.__head = self.__Node()
        self.__tail = self.__Node()
        self.__head.next = self.__tail
        self.__head.pre = None
        self.__tail.pre = self.__head
        self.__tail.next = None
        self.__head.key = 0
        self.__tail.key = None

    def push(self, key):
        newOne = self.__Node(key, self.__tail.pre, self.__tail)
        newOne.pre.next = newOne
        newOne.next.pre = newOne
        self.__head.key += 1

    def front(self):
        return self.__head.next.key

    def pop(self):
        temp = self.__head.next
        self.__head.next = temp.next
        temp.next.pre = self.__head
        self.__head.key -= 1
        del(temp)

    def size(self):
        return self.__head.key

    def clear(self):
        for x in range(self.__head.key):
            self.pop()
            self.__head.key = 0
            

    def getIter(self):
        cur = self.__head.next
        while cur != self.__tail:
            yield cur.key
            cur = cur.next

queue = Queue()
def show(ls):
    print(list(ls))

for x in range(20):
    queue.push(x)
    show(queue.getIter())
    print(queue.size())

for x in range(20):
    print(queue.front()); queue.pop()
    show(queue.getIter())

for x in range(10):
    queue.push(x)

show(queue.getIter()); print(queue.size())

queue.clear();
show(queue.getIter()); print(queue.size())
