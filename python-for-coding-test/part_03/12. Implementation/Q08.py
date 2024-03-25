import sys
input = sys.stdin.readline

S = list(input().strip())
alpahbet = []
numstr = []

for s in S:
    if s.isdigit():
        numstr.append(s)
    else:
        alpahbet.append(s)

alpahbet.sort()
num = list(map(int, numstr))
num.sort()

for a in alpahbet:
    print(a, end="")
print(sum(num))
