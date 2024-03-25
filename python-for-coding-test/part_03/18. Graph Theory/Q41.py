import sys
input = sys.stdin.readline

N, M = map(int, input().split())

graph = []

for i in range(N):
    graph.append(list(map(int, input().split())))

route = list(map(int, input().split()))

parent = [0 for _ in range(N + 1)]

for i in range(1, N + 1):
    parent[i] = i

def find(parent, a):
    if parent[a] != a:
        parent[a] = find(parent, parent[a])
    return parent[a]

def union(parent, a, b):
    pa = find(parent, a)
    pb = find(parent, b)
    if pa < pb:
        parent[pb] = pa
    else:
        parent[pa] = pb

for i in range(1, N + 1):
    for j in range(1, N + 1):
        if graph[i - 1][j - 1] == 1 and find(parent, i) != find(parent, j):
            union(parent, i, j)

flag = False
firstParent = find(parent, route[0])
for r in route[1:-1]:
    par = find(parent, r)
    if firstParent != par:
        flag = True
        break

if flag == False:
    print("YES")
else:
    print("NO")