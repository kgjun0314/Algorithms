import sys
input = sys.stdin.readline

N, M = map(int, input().split())

Map = []
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
temp = [[0 for i in range(M)] for j in range(N)]
result = 0

def is_valid(y, x):
    return (0 <= y and y <= N - 1 and 0 <= x and x <= M - 1)

def get_score():
    score = 0
    for i in range(N):
        for j in range(M):
            if temp[i][j] == 0:
                score += 1
    return score

def infection(y, x):
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if(is_valid(ny, nx)):
            if temp[ny][nx] == 0:
                temp[ny][nx] = 2
                infection(ny, nx)

def dfs(count):
    global result
    if count == 3:
        for i in range(N):
            for j in range(M):
                temp[i][j] = Map[i][j]
        for i in range(N):
            for j in range(M):
                if temp[i][j] == 2:
                    infection(i, j)
        result = max(result, get_score())
    else:
        for i in range(N):
            for j in range(M):
                if Map[i][j] == 0:
                    Map[i][j] = 1
                    count += 1
                    dfs(count)
                    Map[i][j] = 0
                    count -= 1

for i in range(N):
    Map.append(list(map(int, input().split())))

dfs(0)
print(result)