import sys
input = sys.stdin.readline

N, M = map(int, input().split())
parent = [0] * (N + 1)
edges = []
costs = []

for i in range(N + 1):
    parent[i] = i

def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent, x, y):
    px = find(parent, x)
    py = find(parent, y)
    if px < py:
        parent[py] = px
    else:
        parent[px] = py

for i in range(M):
    A, B, C = map(int, input().split())
    edges.append((C, A, B))

edges.sort()

for edge in edges:
    if find(parent, edge[1]) != find(parent, edge[2]):
        union(parent, edge[1], edge[2])
        costs.append(edge[0])

print(sum(costs) - costs[-1])