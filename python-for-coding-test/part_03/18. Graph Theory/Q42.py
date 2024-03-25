import sys
input = sys.stdin.readline

def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent, x, y):
    px = parent[x]
    py = parent[y]
    if(px < py):
        parent[py] = px
    else:
        parent[px] = py

G = int(input().strip())
P = int(input().strip())

parent = [i for i in range(G + 1)]

flights = []

for i in range(P):
    flights.append(int(input()))

answer = 0
for flight in flights:
    data = find(parent, flight)
    if data == 0:
        break
    else:
        union(parent, data, data - 1)
        answer += 1

print(answer)