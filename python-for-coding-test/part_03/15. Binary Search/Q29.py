import sys
input = sys.stdin.readline

N, C = map(int, input().split())

home = []

for i in range(N):
    home.append(int(input()))

home.sort()

minGap = 1
maxGap = home[-1] - home[0]

result = 0

while(minGap <= maxGap):
    mid = (minGap + maxGap) // 2
    value = home[0]
    count = 1
    for i in range(1, N):
        if home[i] >= value + mid:
            value = home[i]
            count += 1
    if count < C:
        maxGap = mid - 1
    else:
        minGap = mid + 1
        result = mid

print(result)