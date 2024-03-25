import sys
input = sys.stdin.readline

S = list(map(int, input().strip()))

answer = S[0]
for i in range(1, len(S)):
    if answer == 0 or answer == 1 or S[i] == 0 or S[i] == 1:
        answer += S[i]
    else:
        answer *= S[i]

print(answer)