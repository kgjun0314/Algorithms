import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

city = []

def Find(a):
    if city[a] == a:
        return a
    else:
        city[a] = Find(city[a])
        return city[a]

def Union(a, b):
    pa = Find(a)
    pb = Find(b)

    if pa <= pb:
        city[pb] = pa
    else:
        city[pa] = pb

N = int(input())
M = int(input())

for i in range(N + 1):
    city.append(i)

for i in range(N):
    L = list(map(int, input().split()))
    for j in range(N):
        if L[j] == 1:
            Union(i + 1, j + 1)

plan = list(map(int, input().split()))

flag = False

for i in range(len(plan)):
    if Find(plan[0]) != Find(plan[i]):
        flag = True

if flag == True:
    print("NO")
else:
    print("YES")