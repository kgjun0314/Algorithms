import sys
input = sys.stdin.readline

def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent, a, b):
    pa = find(parent, a)
    pb = find(parent, b)
    if pa < pb:
        parent[pb] = pa
    else:
        parent[pa] = pb

V, E = map(int, input().split())

parent = [0] * (V + 1)
edges = []
result = 0

for i in range(1, V + 1):
    parent[i] = i

for i in range(E):
    a, b, cost = map(int, input().split())
    edges.append((cost, a, b))

edges.sort()

for edge in edges:
    cost, a, b = edge
    if find(parent, a) != find(parent, b):
        union(parent, a, b)
        result += cost

print(result)