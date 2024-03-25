import sys
from collections import deque
input = sys.stdin.readline

N = int(input().strip())
K = int(input().strip())

Map = [[0] * (N + 1) for _ in range(N + 1)]
direction_info = []

for _ in range(K):
    r, c = map(int, input().split())
    Map[r][c] = 1

L = int(input().strip())

for _ in range(L):
    X, C = input().split()
    direction_info.append((int(X), C))

dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

def isValid(y, x):
    return (1 <= y and y <= N and 1 <= x and x <= N and Map[y][x] != 2)

def turnHead(direction, c):
    if c == 'L':
        direction = (direction - 1) % 4
    else:
        direction = (direction + 1) % 4
    return direction

def simulate():
    y, x = 1, 1
    Map[y][x] = 2
    direction = 0
    time = 0
    turnIndex = 0
    q = deque()
    q.append((y, x))
    while True:
        ny = y + dy[direction]
        nx = x + dx[direction]
        if isValid(ny, nx):
            if Map[ny][nx] == 0:
                Map[ny][nx] = 2
                q.append((ny, nx))
                py, px = q.popleft()
                Map[py][px] = 0
            elif Map[ny][nx] == 1:
                Map[ny][nx] = 2
                q.append((ny, nx))
        else:
            time += 1
            break
        y, x = ny, nx
        time += 1
        if turnIndex < L and time == direction_info[turnIndex][0]:
            direction = turnHead(direction, direction_info[turnIndex][1])
            turnIndex += 1
    return time

print(simulate())
    