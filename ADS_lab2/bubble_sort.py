__author__ = 'olya'

def bubble_sort(sample):
    for i in range(1, len(sample)):
        for j in range(len(sample)-i):
            if sample[j] > sample[j+1]:
                sample[j], sample[j+1] = sample[j+1], sample[j]
    print sample