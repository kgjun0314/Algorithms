import sys

N, M = map(int, sys.stdin.readline().rstrip().split())

D = {}

for i in range(N) :
    name = sys.stdin.readline().rstrip()
    if name not in D and len(name) >= M:
        D[name] = 1
    elif name in D and len(name) >= M:
        D[name] = D[name] + 1

L = sorted(D.items(), key = lambda x : (-x[1], -len(x[0]), x[0]))

for i in L:
    print(i[0])