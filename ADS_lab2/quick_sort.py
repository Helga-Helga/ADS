from random import random

__author__ = 'olya'

def quick_sort(sample):
    if len(sample) > 1:
        pivot = random.choice(sample)
    less = [x for x in sample if x < pivot]
    greater = [x for x in sample if x > pivot]
    equal = [x for x in sample if x == pivot]
    return quick_sort(less) + equal + quick_sort(greater)