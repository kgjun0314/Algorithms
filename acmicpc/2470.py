import sys

input = sys.stdin.readline

x = 0
y = 0

minval = 2000000001

n = int(input())
a = list(map(int, input().split()))

a.sort()

i = 0
j = len(a) - 1

while i < j:
    if a[i] + a[j] <= 0:
        if abs(a[i] + a[j]) < abs(minval):
            minval = a[i] + a[j]
            x = a[i]
            y = a[j]
        i += 1
    elif a[i] + a[j] > 0:
        if abs(a[i] + a[j]) < abs(minval):
            minval = a[i] + a[j]
            x = a[i]
            y = a[j]
        j -= 1

print(x, y)