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

N, M = map(int, input().split())
parent = [0] * (N + 1)

for i in range(1, N + 1):
    parent[i] = i

for i in range(M):
    cmd, a, b = map(int, input().split())
    if cmd == 0:
        union(parent, a, b)
    else:
        if find(parent, a) == find(parent, b):
            print("YES")
        else:
            print("NO")