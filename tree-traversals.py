class Node:    
    def __init__(self,val : int):
        self.val = val
        self.left = None  
        self.right = None
    def value(self):
        return self.val
class Tree:
    def __init__(self,root:Node):
        self.root = root
def preOrder(node : Node):  # n l r
    if node==None:
        return
    print(node.val)
    preOrder(node.left)
    preOrder(node.right)
def inOrder(node : Node):  # n l r
    if node==None:
        return
    inOrder(node.left)
    print(node.val)
    inOrder(node.right)
def postOrder(node : Node):  # n l r
    if node==None:
        return
    postOrder(node.left)
    postOrder(node.right)
    print(node.val)

root = Node(10)
n1 = Node(20)
n2 = Node(30)
n3 = Node(40)
n4 = Node(50)
n5 = Node(60)
n6 = Node(70)


root.left = n1
root.right = n2

n1.left = n3
n1.right = n4

n2.left = n5
n2.right = n6

tree1 = Tree(root)
print("PRE ORDER TRAVERSAL")
preOrder(root)
print("")
print("IN ORDER TRAVERSAL")
inOrder(root)
print("")
print("POST ORDER TRAVERSAL")
postOrder(root)