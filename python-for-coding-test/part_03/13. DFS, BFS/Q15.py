from collections import deque
import sys
input = sys.stdin.readline

N, M, K, X = map(int, input().split())
graph = [[] for i in range(N + 1)]

for i in range(M):
    A, B = map(int, input().split())
    graph[A].append(B)

distance = [-1] * (N + 1)
distance[X] = 0

q = deque()
q.append(X)

while q:
    now = q.popleft()
    for next in graph[now]:
        if distance[next] == -1:
            distance[next] = distance[now] + 1
            q.append(next)

answerList = []
for i in range(1, N + 1):
    if distance[i] == K:
        answerList.append(i)

if len(answerList) == 0:
    print(-1)
else:
    for i in answerList:
        print(i)

