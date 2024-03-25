import sys
input = sys.stdin.readline

S = list(map(int, input().strip()))

cnt = [0, 0]

flag = False
for i in range(len(S)):
    if(S[i] == 0 and flag == False):
        cnt[0] += 1
        flag = True
    elif(S[i] == 1):
        flag = False

flag = False
for i in range(len(S)):
    if(S[i] == 1 and flag == False):
        cnt[1] += 1
        flag = True
    elif(S[i] == 0):
        flag = False

print(min(cnt))