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

for i in range(E):
    a, b = map(int, input().split())
    union(parent, a, b)

print("각 원소가 속한 집합: ")
for i in range(1, V + 1):
    print("{}번 노드의 parent : {}".format(i, find(parent, i)))

print("부모 테이블: ")
for i in range(1, V + 1):
    print("{}: {}".format(i, parent[i]))
