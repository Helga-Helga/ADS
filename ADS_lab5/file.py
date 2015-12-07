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
    datafile = open('input.txt', "r")
    new_data = ''.join(line for line in datafile.readlines() if line.strip() != data.strip())
    datafile.close()
    datafile = open('input.txt', "w")
    datafile.write(new_data)
    datafile.close()
