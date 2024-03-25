import sys
from collections import deque
input = sys.stdin.readline

INF = int(1e9)

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

T = int(input().strip())

def is_valid(y, x):
    return (0 <= y and y < N and 0 <= x and x < N)

for _ in range(T):
    N = int(input().strip())
    Map = []
    for i in range(N):
        Map.append(list(map(int, input().split())))
    # dist 그리드를 만들어서 시작칸을 0으로, 나머지 무한대로 초기화한다
    dist = [[INF for i in range(N)] for j in range(N)]
    dist[0][0] = Map[0][0]
    # 우선 (0, 0)을 큐에 넣는다.
    q = deque()
    q.append((0, 0))
    # BFS를 돌린다.
    while q:
        cur = q.popleft()
        cur_y = cur[0]
        cur_x = cur[1]
        for i in range(4):
            ny = cur_y + dy[i]
            nx = cur_x + dx[i]
            if(is_valid(ny, nx)):
                if(dist[ny][nx] > dist[cur_y][cur_x] + Map[ny][nx]):
                    dist[ny][nx] = dist[cur_y][cur_x] + Map[ny][nx]
                    q.append((ny, nx))
    print(dist[N - 1][N - 1])