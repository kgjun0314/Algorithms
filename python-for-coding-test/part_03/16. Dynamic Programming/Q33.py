import sys
input = sys.stdin.readline

N = int(input().strip())

T = [0] * (N + 1)
P = [0] * (N + 1)
dp = [0] * (N + 1)

for i in range(1, N + 1):
    T[i], P[i] = map(int, input().split())
    for j in range(i):
        if(T[i] + i <= N + 1 and T[j] + j <= i):
            dp[i] = max(dp[i], dp[j] + P[i])

maxVal = dp[1]

for i in range(2, N + 1):
    if dp[i] >= maxVal:
        maxVal = dp[i]

print(maxVal)