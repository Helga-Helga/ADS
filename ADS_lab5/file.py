__author__ = 'olya'

datafile = open('input.txt')


def search(data):
    for line in datafile:
        if data in line:
            return data
    datafile.write(data)
    return data


def delete(data):
    for line in datafile:
        if data in line:
            line.replace(data, '')


def closeFile():
    datafile.close()
