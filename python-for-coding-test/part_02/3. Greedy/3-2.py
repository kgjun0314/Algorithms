N, M, K = map(int, input().split())
data = list(map(int, input().split()))

data.sort()
first = data[N - 1]
second = data[N - 2]

answer = 0
# cnt = 0
# flag = 0

# for i in range(M):
#     if flag == 0:
#         cnt += 1
#         answer += first
#         if cnt == K:
#             flag = 1
#             cnt = 0
#     elif flag == 1:
#         answer += second
#         flag = 0

cnt = int(M / (K + 1)) * K
cnt += M % (K + 1)

answer += (cnt) * first
answer += (M - cnt) * second

print(answer)
