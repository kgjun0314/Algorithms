import sys
input = sys.stdin.readline
INF = int(1e9)

N, M = map(int, input().split())
graph = [[INF for i in range(N + 1)] for j in range(N + 1)]

for i in range(1, N + 1):
    graph[i][i] = 0

for i in range(M):
    A, B = map(int, input().split())
    graph[A][B] = 1

for k in range(1, N + 1):
    for a in range(1, N + 1):
        for b in range(1, N + 1):
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

result = 0

for i in range(1, N + 1):
    cnt = 0
    for j in range(1, N + 1):
        if graph[i][j] != INF or graph[j][i] != INF: # i와 j가 비교 가능한 관계라면
            cnt += 1
    if cnt == N:
        result += 1

print(result)