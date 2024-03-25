import sys
input = sys.stdin.readline

n = int(input().strip())

ugly = [0] * (n + 1)
ugly[1] = 1

mul2 = mul3 = mul5 = 1
next2, next3, next5 = 2, 3, 5

for i in range(2, n + 1):
    ugly[i] = min(next2, next3, next5)

    if ugly[i] == next2:
        mul2 += 1
        next2 = ugly[mul2] * 2
    if ugly[i] == next3:
        mul3 += 1
        next3 = ugly[mul3] * 3
    if ugly[i] == next5:
        mul5 += 1
        next5 = ugly[mul5] * 5


print(ugly[n])