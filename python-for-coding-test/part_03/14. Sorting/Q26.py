import sys
import heapq

input = sys.stdin.readline

N = int(input().strip())

q = []

for i in range(N):
    num = int(input().strip())
    heapq.heappush(q, num)

answer = 0


while len(q) > 1:
    num1 = heapq.heappop(q)
    num2 = heapq.heappop(q)
    answer += num1 + num2
    heapq.heappush(q, num1 + num2)
    
print(answer)