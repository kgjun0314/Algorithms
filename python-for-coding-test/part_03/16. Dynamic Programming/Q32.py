import sys
input = sys.stdin.readline

N = int(input())
data = []
for i in range(N):
    data.append(list(map(int, input().split())))

dp = [[0 for i in range(0, j)] for j in range(1, N + 1)]

dp[0][0] = data[0][0]

for i in range(0, N - 1):
    for j in range(0, i + 1):
        dp[i + 1][j] = max(dp[i][j] + data[i + 1][j], dp[i + 1][j])
        dp[i + 1][j + 1] = max(dp[i][j] + data[i + 1][j + 1], dp[i + 1][j + 1])

maxValue = -1
for i in dp[N - 1]:
    maxValue = max(maxValue, i)

print(maxValue)