def solution(N, stages):
    answer = []
    memnum = len(stages)
    temp = []
    
    for i in range(1, N + 1):
        cnt = stages.count(i)
        if memnum == 0:
            fail = 0
        else:
            fail = cnt / memnum
            
        temp.append((fail, i))
        memnum -= cnt
        
    print(temp)

    temp.sort(key=lambda x : (-x[0], x[1]))
    
    print(temp)

    answer = [i[1] for i in temp]
    
    return answer

N = int(input())
stages = list(map(int, input().split()))

answer = solution(N, stages)

for i in answer:
    print(i, end=" ")