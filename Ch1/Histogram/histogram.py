import sys

def histogram(file_name):
    test_file = open(file_name, 'r')
    lines = test_file.readlines()

    max_len = 0
    len_table = {}
    for line in lines:
        words = line.split()
        for word in words:
            word = word.strip()
            if (len(sys.argv) > 2):
                print(word)
            if len(word) > max_len:
                max_len = len(word)
            if (len(word) not in len_table):
                len_table[len(word)] = 1
            else:
                len_table[len(word)] += 1
    return len_table, max_len

def print_histogram(table):
    len_table = table[0]
    max_len = table[1]
    for i in range(1, max_len+1):
        if i in len_table:
            print(str(i) + "\t" + str(len_table[i]) + "\t" + "-" * len_table[i])
        else:
            print(str(i) + "\t0")

print_histogram(histogram(sys.argv[1]))
