import sys
input = sys.stdin.readline

cnt = 0
L = []
N, K = map(int, input().split())

for i in range(N) :
    value = int(input())
    L.append(value)

L.sort(reverse = True)

for i in L:
    cnt = cnt + K // i
    K = K % i
    if K == 0:
        break

print(cnt)