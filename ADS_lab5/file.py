__author__ = 'olya'

datafile = open('input.txt', "r+")


def search(data):
    for line in datafile:
        if data in line:
            return data
    datafile.write('\n')
    datafile.write(data)
    return data


def delete(data):
    for line in datafile:
        if data not in line:
            datafile.write(data)


def close():
    datafile.close()
