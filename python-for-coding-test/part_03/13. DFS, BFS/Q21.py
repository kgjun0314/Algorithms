import sys
input = sys.stdin.readline
from collections import deque

N, L, R = map(int, input().split())
A = []

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

for _ in range(N):
    A.append(list(map(int, input().split())))

def isValid(y, x):
    return (0 <= y and y < N and 0 <= x and x < N)

def BFS(y, x, index): # index는 연합의 번호를 의미
    united = []
    united.append((y, x))
    union[y][x] = index
    q = deque()
    q.append((y, x))
    Sum = A[y][x]
    count = 1
    while q:
        y, x = q.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if(isValid(ny, nx)):
                if(union[ny][nx] == -1 and L <= abs(A[y][x] - A[ny][nx]) and abs(A[y][x] - A[ny][nx]) <= R): #인접한 지역이 연합이 없는 지역이고 인구 차이가 L이상 R이하라면
                    united.append((ny, nx))
                    union[ny][nx] = index
                    q.append((ny, nx))
                    Sum += A[ny][nx]
                    count += 1
    for i, j in united: # 인구 이동
        A[i][j] = Sum // count


total_count = 0

while True:
    union = [[-1] * N for _ in range(N)]
    index = 0
    for i in range(N):
        for j in range(N):
            if union[i][j] == -1:
                BFS(i, j, index)
                index += 1
    if index == N * N: # 연합의 수가 국가의 수와 일치하면 이동이 없는 것.
        break
    total_count += 1

print(total_count)