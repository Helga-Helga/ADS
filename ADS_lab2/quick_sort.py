__author__ = 'olya'

from random import randint

def quick_sort(sample):
    if len(sample) < 2:
        return sample
    pivot = sample[randint(0, len(sample)-1)]
    less = [x for x in sample if x < pivot]
    greater = [x for x in sample if x > pivot]
    equal = [x for x in sample if x == pivot]
    return quick_sort(less) + equal + quick_sort(greater)