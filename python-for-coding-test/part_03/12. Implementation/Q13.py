import sys
input = sys.stdin.readline

Map = []
houses = []
chickens = []
answer = int(1e9)

def calculateDist():
    global answer
    totalChickenDist = 0

    for house in houses:
        chickenDist = int(1e9)
        for chicken in chickens:
            if chicken[2] == True:
                if abs(house[0] - chicken[0]) + abs(house[1] - chicken[1]) < chickenDist:
                    chickenDist = abs(house[0] - chicken[0]) + abs(house[1] - chicken[1])
        totalChickenDist += chickenDist

    if(totalChickenDist < answer):
        answer = totalChickenDist

def selectChicken(index, count): # 치킨집의 모든 조합을 계산
    if(count == M):
        calculateDist()
    for i in range(index, len(chickens)):
        if(chickens[i][2] == False):
            chickens[i][2] = True
            selectChicken(i, count + 1)
            chickens[i][2] = False

N, M = map(int, input().split())

for i in range(N):
    Map.append(list(map(int, input().split())))

for i in range(N):
    for j in range(N):
        if Map[i][j] == 1:
            houses.append([i, j])
        elif Map[i][j] == 2:
            chickens.append([i, j, False])

selectChicken(0, 0)
print(answer)