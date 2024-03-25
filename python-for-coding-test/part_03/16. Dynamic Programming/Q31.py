import sys
input = sys.stdin.readline

T = int(input().strip())

while T:
    n, m = map(int, input().split())
    data = list(map(int, input().split()))
    dp = [0] * (n * m)

    for i in range(n):
        dp[i * m] = data[i * m]

    for k in range(1, m):
        for i in range(n):
            if i * m + k - m >= 0:
                dp[i * m + k - m] = max(dp[i * m + k - m], dp[i * m + k - 1] + data[i * m + k - m])
            if i * m + k <= n * m - 1:
                dp[i * m + k] = max(dp[i * m + k], dp[i * m + k - 1] + data[i * m + k])
            if i * m + k + m <= n * m - 1:
                dp[i * m + k + m] = max(dp[i * m + k + m], dp[i * m + k - 1] + data[i * m + k + m])

    maxNum = -1
    for i in range(1, n + 1):
        maxNum = max(maxNum, dp[i * m - 1])

    print(maxNum)

    T -= 1