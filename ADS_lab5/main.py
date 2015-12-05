from tree import Node

f = open('input.txt')
tree = Node('')
for line in f:
    tree.insert(line)
tree.printTree()
f.close()
