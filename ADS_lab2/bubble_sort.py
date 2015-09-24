__author__ = 'olya'


def bubble_sort(sample):
    m = 0
    k = 0
    for i in range(1, len(sample)):
        for j in range(len(sample) - i):
            k += 1
            if sample[j] > sample[j + 1]:
                sample[j], sample[j + 1] = sample[j + 1], sample[j]
                m += 1
    print 'Comparisons: ', k
    print 'Exchanges: ', m
