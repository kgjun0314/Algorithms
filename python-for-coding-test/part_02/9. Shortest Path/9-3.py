import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)

N, M, C = map(int, input().split())
graph = [[] for i in range(N + 1)]
distance = [INF] * (N + 1)

for i in range(M):
    X, Y, Z = map(int, input().split())
    graph[X].append((Y, Z))

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for next in graph[now]:
            next_cur = next[0]
            next_dist = next[1]

            cost = dist + next_dist
            if cost < distance[next_cur]:
                distance[next_cur] = cost
                heapq.heappush(q, (cost, next_cur))

dijkstra(C)

count = 0
max_dist = -1
for d in distance:
    if d != INF:
        count += 1
        max_dist = max(max_dist, d)

print(count - 1, max_dist)

