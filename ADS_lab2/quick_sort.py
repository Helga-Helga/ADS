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

def real_quick_sort(sample, p, r):
    if p < r:
        q = partition(sample, p, r)
        real_quick_sort(sample, p, q - 1)
        real_quick_sort(sample, q + 1, r)

def partition(sample, p, r):
    x = sample[r]
    i = p - 1
    for j in range(p, r):
        if sample[j] <= x:
            i += 1
            sample[i], sample[j] = sample[j], sample[i]
    sample[i+1], sample[r] = sample[r], sample[i+1]
    return i+1