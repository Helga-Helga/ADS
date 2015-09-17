__author__ = 'olya'

from sys import argv
from random import randint
from bubble_sort import bubble_sort
from quick_sort import quick_sort

s = [randint(0, 5) for i in range(int(argv[1]))]
print(s)

print("Bubble_sort: ")
bubble_sort(s)
print "Quick_sort: "
s = quick_sort(s)
print(s)

def check(a, b):
    if a > b:
        raise Exception('Not sorted: ' + str(a) + ' should not be greater than ' + str(b))
    return b

reduce(check, s)


