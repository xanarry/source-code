class Node():#定义节点
    """docstring for Node"""
    def __init__(self, key, next = None):
        self.key = key#元素
        self.next = next#下一个元素的引用

def insert(head, key):
    '''插入新的元素, 头插法'''
    newOne = Node(key, head.next)
    head.next = newOne

def search(head, key):
    '''搜索链表是否包含某个元素'''
    while head and head.key != key:
        head = head.next
    return True if head else False

def deleteNode(head, key):
    '''删除链表中的一个元素, 重复的只删除第一个'''
    pre = head
    cur = head.next
    while cur and cur.key != key:
        pre = cur
        cur = cur.next
    res = None
    if cur:
        pre.next = cur.next
        res = cur.key
        del(cur)
    return res

def output(head):
    '''遍历输出链表'''
    head = head.next;
    while head:
        print(head.key, end = " ")
        head = head.next
    print()


linkList = Node(None)
for i in range(10):
    insert(linkList, i)

output(linkList)