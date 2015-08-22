import time
class Node():
    """docstring for double linked list Node"""
    def __init__(self):
        self.key = None
        self.next = None
        self.pre = None  

def insert(head, key):
    '''insert a new key into double linkList'''
    newOne = Node()
    newOne.key = key
    newOne.next = head.next
    newOne.pre = head
    head.next = newOne
    newOne.next.pre = newOne

def deleteNode(head, key):
    '''delete one key from the list'''
    curP = head
    preP = head.next
    while curP != tail and curP.key != key:
        preP = curP
        curP = curP.next
    #do deletion only when find destinct node, else down
    if curP != tail:
        preP.next = curP.next
        curP.next.pre = preP


def search(head, key):
    '''searching each node in the list'''
    temp = head.next
    while temp != tail:
        if temp.key == key:
            return True
        temp = temp.next
    return False

def traverse(head):
    '''from head to tail'''
    temp = head.next
    while temp != tail:
        print(temp.key, end = " ")
        temp = temp.next
    print()

def reverseTraverse(tail):
    '''from tail to head'''
    temp = tail.pre
    while temp != head:
        print(temp.key, end = " ")
        temp = temp.pre
    print()

def init():
    '''initialize linkList to get head and tail node'''
    head = Node()
    tail = Node()
    head.next = tail
    head.pre = None
    tail.pre = head
    tail.next = None
    return head, tail
    
#entry------------------------
#variables definded here is avielable for all function below, just like a globle
head, tail = init()
for i in range(10):
    insert(head, i)

traverse(head)
reverseTraverse(tail)
print(search(head, 8))
print(search(head, 90))

for i in range(10):
    deleteNode(head, i)
    traverse(head)


time.sleep(4)