dp = [[0 for i in range(31)] for j in range(31)]

def C(n, r):
    if dp[n][r] != 0 :
        return dp[n][r]
    elif r == 0 or r == n :
        dp[n][r] = 1
        return dp[n][r]
    else :
        dp[n][r] = C(n - 1, r - 1) + C(n - 1, r)
        return dp[n][r]

T = int(input())
for i in range(T):
    N, M = map(int, input().split(" "))
    print(C(M, N))
