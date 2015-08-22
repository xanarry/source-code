class Node():
    def __init__(self, key = None, left = None, right = None):
        self.key = key
        self.left = left
        self.right = right

def insert(root, key):
    if not root:
        root = Node(key)
    elif key >= root.key:
        root.right = insert(root.right, key)
    else:
        root.left = insert(root.left, key)
    return root

def delete(root, key):
    if not root:
        return
    if key > root.key:
        root.right = delete(root.right, key)
    elif key < root.key:
        root.left = delete(root.left, key)
    else:
        if root.right and root.left:
            successor = findMin(root.right)
            root.key = successor.key
            root.right = delete(root.right, successor.key)
        else:
            temp = root
            if not root.right:
                root = root.left
            elif not root.left:
                root = root.right
            del(temp)  
    return root         

def preOrderTraverse(root):
    def recursion(root):
        if root:
            print(root.key, end = " ")
            recursion(root.left)
            recursion(root.right)
    recursion(root)
    print()

def search(root, key):
    if not root or root.key == key:
        return root
    elif key > root.key:
        return search(root.right, key)
    else:
        return search(root.left, key)

def findMax(root):
    return root if not root or not root.right else findMax(root.right)

def findMin(root):
    return root if not root or not root.left else findMin(root.left)

a = [3, 4, 8, 2, 1, 6]
root = None

print("insert")
for x in a:
    root = insert(root, x)
    preOrderTraverse(root)

print("delete")
for x in a:
    root = delete(root, x)
    preOrderTraverse(root)

