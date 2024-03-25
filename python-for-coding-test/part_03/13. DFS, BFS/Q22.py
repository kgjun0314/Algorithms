from collections import deque
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def isvalid(y, x, N):
    return (0 <= y < N and 0 <= x < N)

def solution(board):
    pos = ((0, 0), (0, 1))
    N = len(board)

    q = deque()
    visited = set()
    visited.add(pos)
    q.append((pos, 0))

    while q:
        cur, cost = q.popleft()
        if (N - 1, N - 1) in cur:
            return cost
        
        next_pos = []
        cur1_y, cur1_x, cur2_y, cur2_x = cur[0][0], cur[0][1], cur[1][0], cur[1][1]
        for i in range(4):
            n_cur1_y = cur1_y + dy[i]
            n_cur1_x = cur1_x + dx[i]
            n_cur2_y = cur2_y + dy[i]
            n_cur2_x = cur2_x + dx[i]
            if isvalid(n_cur1_y, n_cur1_x, N) and isvalid(n_cur2_y, n_cur2_x, N):
                if board[n_cur1_y][n_cur1_x] == 0 and board[n_cur2_y][n_cur2_x] == 0:
                    next_pos.append(((n_cur1_y, n_cur1_x), (n_cur2_y, n_cur2_x)))
        
        if cur1_y == cur2_y:
            for i in [-1, 1]:
                if isvalid(cur1_y + i, cur1_x, N) and isvalid(cur2_y + i, cur2_x, N):
                    if board[cur1_y + i][cur1_x] == 0 and board[cur2_y + i][cur2_x] == 0:
                        if isvalid(cur1_y, cur1_x, N) and isvalid(cur1_y + i, cur1_x, N):
                            next_pos.append(((cur1_y, cur1_x), (cur1_y + i, cur1_x)))
                        if isvalid(cur2_y, cur2_x, N) and isvalid(cur2_y + i, cur2_x, N):
                            next_pos.append(((cur2_y, cur2_x), (cur2_y + i, cur2_x)))
        elif cur1_x == cur2_x:
            for i in [-1, 1]:
                if isvalid(cur1_y, cur1_x + i, N) and isvalid(cur2_y, cur2_x + i, N):
                    if board[cur1_y][cur1_x + i] == 0 and board[cur2_y][cur2_x + i] == 0:
                        if isvalid(cur1_y, cur1_x, N) and isvalid(cur1_y, cur1_x + i, N):
                            next_pos.append(((cur1_y, cur1_x), (cur1_y, cur1_x + i)))
                        if isvalid(cur2_y, cur2_x, N) and isvalid(cur2_y, cur2_x + i, N):
                            next_pos.append(((cur2_y, cur2_x), (cur2_y, cur2_x + i)))
        
        for next in next_pos:
            if next not in visited:
                q.append((next, cost + 1))
                visited.add(next)
        
    return 0



N = int(input())
board = []
for _ in range(N):
    board.append(list(map(int, input().split())))

print(solution(board))