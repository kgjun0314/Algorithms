import sys
input = sys.stdin.readline

N = int(input().strip())

data = list(map(int, input().split()))
data.sort()

target = 1

for x in data:
    if target < x:
        break
    target += x

print(target)