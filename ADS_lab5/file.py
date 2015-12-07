__author__ = 'olya'


def search(data):
    datafile = open('input.txt', "r+")
    for line in datafile:
        if data == line:
            return data
    datafile.write('\n')
    datafile.write(data)
    datafile.close()
    return data


def delete(data):
    datafile = open('input.txt', "r+")
    for line in datafile:
        if data in line:
            line.replace(data, '')
    datafile.close()
