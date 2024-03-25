import sys
input = sys.stdin.readline

N = int(input())
data = list(map(int, input().split()))

data = data[::-1]

dp = [0 for i in range(N)]

for i in range(N):
    dp[i] = 1
    for j in range(i):
        if data[j] < data[i]:
            dp[i] = max(dp[i], dp[j] + 1)

Max = -1
for i in dp:
    if i > Max:
        Max = i

print(N - Max)