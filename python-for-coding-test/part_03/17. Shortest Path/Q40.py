import sys
from collections import deque
input = sys.stdin.readline

INF = int(1e9)

N, M = map(int, input().split())
Map = [[] for i in range(N + 1)]
dist = [INF for i in range(N + 1)]
dist[0] = 0
dist[1] = 0
q = deque()
for i in range(M):
    A, B = map(int, input().split())
    Map[A].append(B)
    Map[B].append(A)

q.append(1)

while q:
    cur = q.popleft()
    for i in Map[cur]:
        if dist[i] > dist[cur] + 1:
            dist[i] = dist[cur] + 1
            q.append(i)

maxVal = -1
ans = 0
for i in range(len(dist)):
    if dist[i] > maxVal:
        maxVal = dist[i]
        ans = i

cnt = 0
for i in dist:
    if i == maxVal:
        cnt += 1

print(ans, maxVal, cnt)