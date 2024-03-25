import sys
input = sys.stdin.readline

N, M = map(int, input().split())

riceCakes = list(map(int, input().split()))

start = 0
end = max(riceCakes)

result = 0

while(start <= end):
    total = 0
    H = (start + end) // 2
    for riceCake in riceCakes:
        if riceCake - H > 0:
            total += riceCake - H
    if total < M:
        end = H - 1
    else:
        result = H
        start = H + 1

print(result)