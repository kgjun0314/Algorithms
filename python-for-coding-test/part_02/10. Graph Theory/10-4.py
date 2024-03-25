from collections import deque
import copy
import sys
input = sys.stdin.readline

N = int(input())
indegree = [0] * (N + 1)
times = [0] * (N + 1)
graph = [[] for i in range(N + 1)]

for i in range(1, N + 1):
    data = list(map(int, input().split()))
    times[i] = data[0]
    for j in data[1:-1]:
        graph[j].append(i)
        indegree[i] += 1

def topological_sort():
    result = copy.deepcopy(times)
    q = deque()
    for i in range(1, N + 1):
        if indegree[i] == 0:
            q.append(i)
    
    while q:
        now = q.popleft()
        for next in graph[now]:
            result[next] = max(result[next], result[now] + times[next])
            indegree[next] -= 1
            if indegree[next] == 0:
                q.append(next)

    for i in range(1, N + 1):
        print(result[i])

topological_sort()