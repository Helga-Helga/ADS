__author__ = 'olya'


class Node:
    def __init__(self, data=None, parent=None, left=None, right=None):
        self.data = data
        self.parent = parent
        self.left = left
        self.right = right

    def insert(self, data=None):
        if data < self.data:
            if self.left is None:
                self.left = Node(data, self)
            else:
                self.left.insert(data)
        elif data > self.data:
            if self.right is None:
                self.right = Node(data, self)
            else:
                self.right.insert(data)
        else:
            self.data = data

    def printTree(self):
        if self.left:
            self.left.printTree()
        print self.data
        if self.right:
            self.right.printTree()

    def search(self, data, parent=None):
        if data < self.data:
            if self.left is None:
                self.left = Node(data)
                return data
            return self.left.search(data, self)
        elif data > self.data:
            if self.right is None:
                self.right = Node(data)
                return data
            return self.right.search(data, self)
        elif data == self.data:
            return self.data



