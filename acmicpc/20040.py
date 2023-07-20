import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

parent = []
cnt = 0
flag = False

def Find(x):
    if parent[x] != x:
        parent[x] = Find(parent[x])
    return parent[x]

def Union(a, b):
    pa = Find(a)
    pb = Find(b)
    if pa <= pb:
        parent[pb] = pa
    else:
        parent[pa] = pb

n, m = map(int, input().split())

for i in range(n):
    parent.append(i)

for i in range(1, m + 1):
    A, B = map(int, input().split())
    if flag == False and Find(A) == Find(B):
        cnt = i
        flag = True
    Union(A, B)

print(cnt)