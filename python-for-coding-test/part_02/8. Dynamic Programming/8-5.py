import sys
input = sys.stdin.readline

N, M = map(int, input().split())

coins = []
for i in range(N):
    coins.append(int(input().strip()))

dp = [10001] * (M + 1)

coins.sort()

for coin in coins:
    if coin <= M:
        dp[coin] = 1

for k in coins:
    for i in range(k, M + 1):
        dp[i] = min(dp[i], dp[i - k] + 1)

if(dp[M] == 10001):
    print(-1)
else:
    print(dp[M])