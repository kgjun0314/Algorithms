import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline
L = []

def Find(a):
    if L[a] == a:
        return a
    else:
        L[a] = Find(L[a])
        return L[a]

def Union(a, b):
    if a <= b:
        L[Find(b)] = Find(a)
    else:
        L[Find(a)] = Find(b)

n, m = map(int, input().split())

for i in range(n + 1):
    L.append(i)

for i in range(m):
    cmd, a, b = map(int, input().split())
    if cmd == 0:
        Union(a, b)
    else:
        if Find(a) == Find(b):
            print("YES")
        else:
            print("NO")