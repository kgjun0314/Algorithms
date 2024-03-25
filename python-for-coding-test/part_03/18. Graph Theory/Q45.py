import sys
input = sys.stdin.readline
from collections import deque

T = int(input())

def topologicalSort(indegree, n):
    q = deque()

    for i in range(1, n + 1):
        if indegree[i] == 0:
            q.append(i)
    
    result = []

    while q:
        now = q.popleft()
        result.append(now)
        for i in graph[now]:
            indegree[i] -= 1
            if indegree[i] == 0:
                q.append(i)

    return result

for test in range(T):

    n = int(input())
    t = list(map(int, input().split()))

    graph = [[] for i in range(n + 1)]
    indegree = [0] * (n + 1)

    for i in range(len(t)):
        for j in range(i + 1, len(t)):
            graph[t[i]].append(t[j])
            indegree[t[j]] += 1

    m = int(input())
    for _ in range(m):
        a, b = map(int, input().split())
        if a in graph[b]:
            graph[b].remove(a)
            indegree[a] -= 1
            graph[a].append(b)
            indegree[b] += 1
        elif b in graph[a]:
            graph[a].remove(b)
            indegree[b] -= 1
            graph[b].append(a)
            indegree[a] += 1

    result = topologicalSort(indegree, n)

    if len(result) == n:
        for i in result:
            print(i, end=" ")
        print()
    else:
        print("IMPOSSIBLE")