import sys
input = sys.stdin.readline

N = int(input())

numOfGroup = 0
count_array = [0] * (N + 1)

data = list(map(int, input().split()))

for i in data:
    count_array[i] += 1

for i in range(1, N + 1):
    if count_array[i] >= i:
        numOfGroup += 1

print(numOfGroup)