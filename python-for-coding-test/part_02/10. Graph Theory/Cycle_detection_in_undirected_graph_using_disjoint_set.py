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

for i in range(1, V + 1):
    parent[i] = i

Cycle = False

for i in range(E):
    a, b = map(int, input().split())
    if find(parent, a) == find(parent, b):
        Cycle = True
        break
    else:
        union(parent, a, b)

if Cycle:
    print("사이클이 발생했습니다.")
else:
    print("사이클이 발생하지 않았습니다.")