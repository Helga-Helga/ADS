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
        i, j = get_corners(sample, p, r, q)
        real_quick_sort(sample, p, i)
        real_quick_sort(sample, j, r)

def partition(sample, p, r):
    x = sample[r]
    i = p -1
    for j in range(p, r):
        if sample[j] < x:
            i += 1
            sample[i], sample[j] = sample[j], sample[i]
    sample[i+1], sample[r] = sample[r], sample[i+1]
    return i+1

def get_corners(sample, p, r, q):
    i, j = q - 1, q + 1
    while sample[i] == sample[q] and i > p:
        i -= 1
    while sample[j] == sample[q] and j < r:
        j += 1
    return i, j