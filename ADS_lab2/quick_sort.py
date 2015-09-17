__author__ = 'olya'

from random import randint

def quick_sort(sample, p, r):
    if p < r:
        q = partition(sample, p, r)
        quick_sort(sample, p, q - 1)
        quick_sort(sample, q+1, r)

def partition(sample, p, r):
    x = sample[r]
    i = p - 1
    for j in range(p, r-1):
        if sample[j] <= x:
            i += 1
            sample[i], sample[j] = sample[j], sample[i]
    sample[i+1], sample[r] = sample[r], sample[i+1]
    return i+1
