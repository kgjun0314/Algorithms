N = int(input())

L = []
S = set(L)
cnt = 0

for i in range(N) :
    cmd = input()
    if cmd == "ENTER" :
        S = set(L)
        cnt += len(S)
        L = []
        S = set(L)
        continue
    else :
        L.append(cmd)

S = set(L)
cnt += len(S)

print(cnt)
