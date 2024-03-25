import sys
input = sys.stdin.readline

N = int(input())
array = []

for i in range(N):
    name, score = input().split()
    score = int(score)
    array.append((score, name))

array.sort()

for i in array:
    print(i[1], end=" ")