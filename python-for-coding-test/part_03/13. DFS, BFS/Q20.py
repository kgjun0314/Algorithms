import sys
input = sys.stdin.readline

N = int(input())
Map = []
temp = [[0 for i in range(N)] for j in range(N)]
count = 0
studentNum = 0
flag = False

for _ in range(N):
    Map.append(list(input().split()))

def isValid(y, x):
    return (0 <= y and y < N and 0 <= x and x < N)

def watch(y, x):
    global studentNum
    ny = y - 1
    while isValid(ny, x):
        if temp[ny][x] == 'O':
            break
        if temp[ny][x] == 'S':
            studentNum += 1
            break
        ny = ny - 1

    ny = y + 1
    while isValid(ny, x):
        if temp[ny][x] == 'O':
            break
        if temp[ny][x] == 'S':
            studentNum += 1
            break
        ny = ny + 1

    nx = x - 1
    while isValid(y, nx):
        if temp[y][nx] == 'O':
            break
        if temp[y][nx] == 'S':
            studentNum += 1
            break
        nx = nx - 1
        
    nx = x + 1
    while isValid(y, nx):
        if temp[y][nx] == 'O':
            break
        if temp[y][nx] == 'S':
            studentNum += 1
            break
        nx = nx + 1

def dfs(count):
    global studentNum
    if count == 3:
        for i in range(N):
            for j in range(N):
                temp[i][j] = Map[i][j]
        studentNum = 0
        for i in range(N):
            for j in range(N):
                if temp[i][j] == 'T':
                    watch(i, j)
        if studentNum == 0:
            print("YES")
            quit()
    else:
        for i in range(N):
            for j in range(N):
                if Map[i][j] == 'X':
                    Map[i][j] = 'O'
                    count += 1
                    dfs(count)
                    Map[i][j] = 'X'
                    count -= 1

dfs(count)
print("NO")