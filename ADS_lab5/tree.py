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

    def printTree(self, i=0):
        print '%s %s' % ('|' * i, self.data.strip())
        if self.left:
            self.left.printTree(i + 1)
        if self.right:
            self.right.printTree(i + 1)

    def search(self, data, parent=None):
        if data < self.data:
            if self.left is None:
                self.left = Node(data)
                return self
            return self.left.search(data, self)
        elif data > self.data:
            if self.right is None:
                self.right = Node(data)
                return self
            return self.right.search(data, self)
        elif data == self.data:
            return self

    def delete(self, data):
        node = self.search(data)
        if node is not None:
            count = node.childrenCount()
            if count == 0:
                if node.parent:
                    if node.parent.left is node:
                        node.parent.left = None
                    else:
                        node.parent.right = None
                    del node
                else:
                    self.data = None
            elif count == 1:
                if node.left:
                    n = node.left
                else:
                    n = node.right
                if node.parent:
                    if node.parent.left is node:
                        node.parent.left = n
                    else:
                        node.parent.right = n
                    del node
                else:
                    self.left = n.left
                    self.right = n.right
                    self.data = n.data
            else:
                parent = node
                successor = node.right
                while successor.left:
                    parent = successor
                    successor = successor.left
                node.data = successor.data
                if parent.left == successor:
                    parent.left = successor.right
                else:
                    parent.right = successor.right

    def childrenCount(self):
        count = 0
        if self.left:
            count += 1
        if self.right:
            count += 1
        return count
