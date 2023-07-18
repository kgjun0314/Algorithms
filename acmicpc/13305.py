import sys
input = sys.stdin.readline

N = int(input())
d = list(map(int, input().split()))
c = list(map(int, input().split()))

cost = d[0] * c[0]
curCost = c[0]

for i in range(1, len(d)):
    if curCost < c[i]:
        cost += curCost * d[i]
    else:
        curCost = c[i]
        cost += curCost * d[i]

print(cost)