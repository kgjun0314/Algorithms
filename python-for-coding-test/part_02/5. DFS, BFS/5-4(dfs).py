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

def dfs(y, x):
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if(is_valid(ny, nx)):
            if(visited[ny][nx] == 0 and Map[ny][nx] == 1):
                visited[ny][nx] = 1
                Map[ny][nx] += Map[y][x]
                if visited[N - 1][M - 1] == 1:
                    break;
                dfs(ny, nx)


dfs(0, 0)
print(Map[N - 1][M - 1])