def possible(answer):
    for x, y, a in answer:
        if a == 0: # 기둥에 대해
            if y == 0 or [x - 1, y, 1] in answer or [x, y, 1] in answer or [x, y - 1, 0] in answer: # 땅위 or 보 끝의 기둥 or 기둥 위의 기둥 이라면 가능
                continue
            return False
        elif a == 1: # 보에 대해
            if [x, y - 1, 0] in answer or [x + 1, y - 1, 0] in answer or ([x - 1, y, 1] in answer and [x + 1, y, 1] in answer): # 끝 부분이 기둥 or 보로 연결 이라면 가능
                continue
            return False
    return True

def solution(n, build_frame):
    answer = []
    for frame in build_frame:
        x, y, a, b = frame
        if b == 0: # 삭제의 경우
            answer.remove([x, y, a])
            if not possible(answer): # 삭제 불가능하면 (불가능한 케이스가 발생하면) 다시 추가
                answer.append([x, y, a])
        elif b == 1: # 설치의 경우
            answer.append([x, y, a])
            if not possible(answer): # 설치 불가능하면 (불가능한 케이스가 발생하면) 다시 삭제
                answer.remove([x, y, a])
    return sorted(answer)

n = int(input())
frame_num = int(input())
build_frame = []
for _ in range(frame_num):
    build_frame.append(list(map(int, input().split())))

print(solution(n, build_frame))