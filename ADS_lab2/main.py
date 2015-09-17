__author__ = 'olya'

from sys import argv
from random import randint
from bubble_sort import bubble_sort
from quick_sort import quick_sort

s = [randint(0, 5) for i in range(int(argv[1]))]
print(s)

bubble_sort(s)
quick_sort(s)

