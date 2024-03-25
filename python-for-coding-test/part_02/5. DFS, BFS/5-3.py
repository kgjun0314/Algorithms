N, M = map(int, input().split())

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
visited = [[0 for i in range(M)] for j in range(N)]

Map = []
for i in range(N):
    Map.append(list(map(int, input())))

cnt = 0

def isValid(y, x):
    return (0 <= y and y <= N - 1 and 0 <= x and x <= M - 1)

def dfs(y, x):
    visited[y][x] = 1
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if isValid(ny, nx):
            if visited[ny][nx] == 0 and Map[ny][nx] == 0:
                dfs(ny, nx)


for i in range(N):
    for j in range(M):
        if visited[i][j] == 0 and Map[i][j] == 0:
            cnt += 1
            dfs(i, j)

print(cnt)