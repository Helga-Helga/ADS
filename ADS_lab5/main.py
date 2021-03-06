import datetime
from tree import Node
from file import search, delete

tree = Node('')
with open('input.txt') as f:
    for line in f:
        tree.insert(line)
print("1. Print tree\n2. Search node\n3. Delete node\n4. Exit")

ans = True
while ans:
    ans = raw_input("What would you like to do? ")
    if ans == "1":
        print("Tree:")
        tree.printTree()
    elif ans == "2":
        print("Searching node...")
        data = raw_input("Enter node data: ")
        a = datetime.datetime.now()
        print "Node found: ", tree.search(data).data
        b = datetime.datetime.now()
        print "Found in file: ", search(data)
        c = datetime.datetime.now()
        print "Search in tree time: ", b - a
        print "Search in file time: ", c - b
    elif ans == "3":
        print("Deletion node...")
        data = raw_input("Enter node data: ")
        tree.delete(data)
        delete(data)
        print("Node deleted")
    elif ans == "4":
        print("Goodbye")
        ans = None
    else:
        print("Not valid choice. Try again")
