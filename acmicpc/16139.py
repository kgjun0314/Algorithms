import sys
import string

name = sys.stdin.readline().rstrip()

N = int(sys.stdin.readline())

char_list = {}

for char in string.ascii_lowercase :
    char_list[char] = [0]
    count = 0
    for i in range(len(name)):
        if name[i] == char :
            count += 1
        char_list[char].append(count)

for i in range(N):
    alpha, l, r = sys.stdin.readline().split()
    l, r = int(l), int(r)
    print(char_list[alpha][r + 1] - char_list[alpha][l])
