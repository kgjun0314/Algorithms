import sys
from collections import deque
input = sys.stdin.readline

N, K = map(int, input().split())

Graph = []
data = []

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for i in range(N):
    Graph.append(list(map(int, input().split())))
    for j in range(N):
        if(Graph[i][j] != 0):
            data.append((Graph[i][j], 0, i, j))

data.sort()
q = deque(data)

S, X, Y = map(int, input().split())

def is_valid(x, y):
    return (0 <= x and x <= N - 1 and 0 <= y and y <= N - 1)

def infection(virus, s, x, y):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if(is_valid(nx, ny)):
            if(Graph[nx][ny] == 0):
                Graph[nx][ny] = virus
                q.append((virus, s + 1, nx, ny))

while q:
    virus, s, x, y = q.popleft()
    if S == s:
        break
    infection(virus, s, x, y)

print(Graph[X - 1][Y - 1])