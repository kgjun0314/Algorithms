L = int(input())
P = input()

pi = [0 for i in range(L)]
j = 0
for i in range(1, L):
    while j > 0 and P[i] != P[j]:
        j = pi[j - 1]
    if P[i] == P[j]:
        j += 1
        pi[i] = j

ans = L - pi[L - 1]

print(ans)