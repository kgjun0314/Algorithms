import sys
input = sys.stdin.readline

N, M = map(int, input().split())
data = list(map(int, input().split()))

cnt = [0] * (M + 1)

for i in data:
    cnt[i] += 1

ans = 0

for i in range(1, M + 1):
    N -= cnt[i] # 무게 i인 공 제외 남은 공의 개수 : N
    ans += N * cnt[i] # 무게 i인 공과 매핑할 수 있는 경우의 수

print(ans)