__author__ = 'olya'

from sys import argv
from random import randint
from bubble_sort import bubble_sort
from quick_sort import quick_sort, real_quick_sort

s = [randint(0, 5) for i in range(int(argv[1]))]
print(s)

print "Real quick sort: "
real_quick_sort(s, s[0], len(s)-1)
print (s)

def check(a, b):
    if a > b:
        raise Exception('Not sorted: ' + str(a) + ' should not be greater than ' + str(b))
    return b

reduce(check, s)


