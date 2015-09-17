__author__ = 'olya'

def bubble_sort(samples):
    for i in range(len(samples), 0, -1):
        for j in range(0, len(samples) - 1):
            if samples[j] > samples[j+1]:
                samples[j], samples[j+1] = samples[j+1], samples[j]
