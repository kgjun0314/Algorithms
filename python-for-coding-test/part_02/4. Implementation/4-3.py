import sys
input = sys.stdin.readline

N, M = map(int, input().split())
A, B, d = map(int, input().split())
cnt = 1
backFlag = False
cntForBackFlag = 0

direction = [[-1, 0],
             [0, 1],
             [1, 0],
             [0, -1]]

Map = []
visited = [[0 for i in range(M)] for j in range(N)]

for i in range(N):
    Data = list(map(int, input().split()))
    Map.append(Data)

visited[A][B] = 1

def is_valid(A, B):
    return (0 <= A and A <= N - 1 and 0 <= B and B <= M - 1)

while True:
    d -= 1
    if d == -1:
        d = 3
    cntForBackFlag += 1
    if cntForBackFlag == 4:
        nA = A + direction[(d + 2) % 4][0]
        nB = B + direction[(d + 2) % 4][1]
        if is_valid(nA, nB):
            if Map[nA][nB] == 0:
                A = nA
                B = nB
                cntForBackFlag = 0
                continue
            else:
                break
        else:
            break
    nA = A + direction[d][0]
    nB = B + direction[d][1]
    if is_valid(nA, nB):
        if Map[nA][nB] == 0 and visited[nA][nB] == 0:
            visited[nA][nB] = 1
            A = nA
            B = nB
            cnt += 1
            cntForBackFlag = 0

print(cnt)
