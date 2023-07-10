import sys

input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
x = int(input())

a.sort()

i = 0
j = len(a) - 1
cnt = 0

while i <= j and i >= 0 and j < len(a):
    if a[i] + a[j] < x:
        i += 1
    elif a[i] + a[j] == x:
        i += 1
        j -= 1
        cnt += 1
    elif a[i] + a[j] > x:
        j -= 1

print(cnt)