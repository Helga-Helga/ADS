__author__ = 'olya'

from sys import argv
from random import getrandbits
from copy import copy
from bubble_sort import bubble_sort
from quick_sort import quick_sort, real_quick_sort

s = [getrandbits(64) for i in range(int(argv[1]))]
print(s)


def check(a, b):
    if a > b:
        raise Exception('Not sorted: ' + str(a) + ' should not be greater than ' + str(b))
    return b


answer = int(argv[2])
if answer == 1:
    sample = copy(s)
    print "Bubble sort: "
    bubble_sort(sample)
    reduce(check, sample)
elif answer == 2:
    sample = copy(s)
    comparisons, sample = quick_sort(sample)
    print "Quick sort: "
    print 'Comparisons: ', comparisons
    print (sample)
    reduce(check, sample)
elif answer == 3:
    sample = copy(s)
    print "Real quick sort: "
    real_quick_sort(sample, 0, len(sample) - 1)
    print (sample)
    reduce(check, sample)
else:
    raise Exception('Bad input')





