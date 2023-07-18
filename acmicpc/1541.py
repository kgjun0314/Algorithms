n = str(input())
m = n.split('-')

ans = 0
neg = True

if n[0] == '-':
    ans -= sum(map(int, m[1].split('+')))
else:
    ans += sum(map(int, m[0].split('+')))
    neg = False

if neg == True:
    for i in m[2:]:
        ans -= sum(map(int, i.split('+')))
else:
    for i in m[1:]:
        ans -= sum(map(int, i.split('+')))

print(ans)