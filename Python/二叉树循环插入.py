import random

class Node():
	def __init__(self, key = None, left = None, right = None):
		self.key = key
		self.left = left
		self.right = right

def insert(root, key):
    if not root:
        root = Node(key)
    else:
        parent, cur = root, root
        while cur:
            parent = cur
            cur = cur.right if key >= cur.key else cur.left

        if key >= parent.key:
            parent.right = Node(key)
        else:
            parent.left = Node(key)
    return root

def delete(root, key):
    if root:
        #find destination node and its parent
        parent = None
        dest = root
        while dest and dest.key != key:
            parent = dest
            if key > dest.key:
                dest = dest.right
            elif key < dest.key:
                dest = dest.left
            else:
                break
        #if key not in the tree
        if not dest:
            return root

        actualDel = dest

        '''if destination node has both left and right subtree, 
            then find which node we will delete actually'''
        if dest.left and dest.right:
            actualDel = dest.right
            parent = dest
            while actualDel.left:
                parent = actualDel
                actualDel = actualDel.left
            dest.key = actualDel.key
        
        #link the rest tree without the delete node
        if actualDel.left:
            if not parent: #this is for the situation of we'll delete the root, but the root has only left subtree
                root = actualDel.left
            elif actualDel.key >= parent.key:
                parent.right = actualDel.left
            else:
                parent.left = actualDel.left
        else:
            if not parent: #as above
                root = actualDel.right
            elif actualDel.key >= parent.key:
                parent.right = actualDel.right
            else:
                parent.left = actualDel.right
        del(actualDel)
    return root

def findMax(root):
	while root.right:
	   root = root.right
	return root

def findMin(root):
	while root.left:
		root = root.left
	return root

def search(root, key):
	while root:
		if key > root.key:
			root = root.right
		elif key < root.key:
			root = root.left
		else:
			break
	return root

def preOrderTraverse(root):
	def recursion(root):
		if root:
			print(root.key, end = " ")
			recursion(root.left)
			recursion(root.right)
	recursion(root)
	print()

root = None
a = []

for i in range(30): 
    a.append(random.randint(10, 100))

for x in a:
    root = insert(root, x)

print("tree", end = ":   ")
preOrderTraverse(root)

for x in a:
    print("del", x, end = ": ")
    root = delete(root, x)
    preOrderTraverse(root)

    