result = []
count = 0

T = input()
P = input()

pi = [0 for i in range(len(P))]
j = 0
for i in range(1, len(P)):
    while j > 0 and P[i] != P[j]:
        j = pi[j - 1]
    if P[i] == P[j]:
        j += 1
        pi[i] = j

j = 0
for i in range(len(T)):
    while j > 0 and T[i] != P[j]:
        j = pi[j - 1]
    if T[i] == P[j]:
        if j == (len(P) - 1):
            result.append(i - len(P) + 2)
            count += 1
            j = pi[j]
        else:
            j += 1

print(count)
for i in result:
    print(i, end = " ")