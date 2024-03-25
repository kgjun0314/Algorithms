import sys
input = sys.stdin.readline

def find(parent, x):
    if(parent[x] != x):
        parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent, x, y):
    x = find(parent, x)
    y = find(parent, y)
    if(x < y):
        parent[y] = x
    else:
        parent[x] = y

N, M = map(int, input().split())
S = 0
MSTVal = 0
edges = []
parent = [i for i in range(N)]

for i in range(M):
    X, Y, Z = map(int, input().split())
    S += Z
    edges.append((Z, (X, Y)))

edges.sort()

for edge in edges:
    if find(parent, edge[1][0]) != find(parent, edge[1][1]):
        union(parent, edge[1][0], edge[1][1])
        MSTVal += edge[0]

print(S - MSTVal)