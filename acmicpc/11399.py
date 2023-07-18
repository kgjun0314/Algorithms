import sys
input = sys.stdin.readline

N = int(input())
cnt = 0

L = list(map(int, input().split()))
L.sort()

for i in range(1, len(L)):
    L[i] = L[i] + L[i - 1]

print(sum(L))