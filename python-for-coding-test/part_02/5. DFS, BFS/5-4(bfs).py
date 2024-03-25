from collections import deque
import sys
input = sys.stdin.readline

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

N, M = map(int, input().split())
visited = [[0 for i in range(M)] for j in range(N)]
Map = []
for i in range(N):
    Map.append(list(map(int, input().strip())))

def is_valid(y, x):
    return (0 <= y and y <= N - 1 and 0 <= x and x <= M - 1)

def bfs(y, x):
    queue = deque()
    queue.append((y, x))
    
    while queue:
        y, x = queue.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if is_valid(ny, nx):
                if Map[ny][nx] == 1:
                    Map[ny][nx] = Map[y][x] + 1
                    queue.append((ny, nx))
    return Map[N - 1][M - 1]

print(bfs(0, 0))