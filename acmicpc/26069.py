N = int(input())

dict = {}
cnt = 0

for i in range(N) :
    A, B = map(str, input().split())
    if A == "ChongChong" or B == "ChongChong" :
        dict[A] = 1
        dict[B] = 1
    elif A in dict and B in dict :
        if dict[A] == 1 or dict[B] == 1 :
            dict[A] = 1
            dict[B] = 1
    elif A in dict and B not in dict :
        if dict[A] == 1 :
            dict[B] = 1
    elif A not in dict and B in dict :
        if dict[B] == 1:
            dict[A] = 1
    elif A not in dict and B not in dict :
        dict[A] = 0
        dict[B] = 0

dict_val = dict.values()

for i in dict_val :
    if i == 1 :
        cnt += 1

print(cnt)