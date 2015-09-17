from random import random

__author__ = 'olya'

def quick_sort(samples):
    if len(samples) > 1:
        pivot = random.choice(samples)
    less = [x for x in samples if x < pivot]
    greater = [x for x in samples if x > pivot]
    equal = [x for x in samples if x == pivot]
    return quick_sort(less) + equal + quick_sort(greater)