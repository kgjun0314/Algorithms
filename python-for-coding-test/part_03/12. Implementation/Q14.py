from itertools import permutations

def solution(n, weak, dist):
    length = len(weak)
    for i in range(length):
        weak.append(weak[i] + n)
    answer = len(dist) + 1

    # 0부터 len(weak) - 1까지의 위치를 각각 시작점으로 설정
    for start in range(length):
        for friends in list(permutations(dist, len(dist))): # dist에서 len(dist)만큼 뽑는 순열에 대해
            count = 1   # 투입할 친구 수 카운트
            position = weak[start] + friends[count - 1] # 친구가 점검할 수 있는 마지막 위치
            for index in range(start, start + length):
                if position < weak[index]: # 점검할 수 있는 위치가 weak[index]에 못미치면 친구 한명 더 투입해야함
                    count += 1
                    if count > len(dist): # 더 투입 불가능하다면 종료한다.
                        break
                    position = weak[index] + friends[count - 1] # 점검할 수 있는 마지막 위치 갱신
            answer = min(answer, count)
    
    if answer > len(dist):
        return -1
    return answer

n = int(input())
weak = list(map(int, input().split()))
dist = list(map(int, input().split()))

print(solution(n, weak, dist))