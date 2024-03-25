import sys
input = sys.stdin.readline

N = input().strip()
mid = len(N) // 2
left = N[:mid]
right = N[mid:]

left_sum = 0
right_sum = 0

for i in range(len(left)):
    left_sum += int(left[i])

for i in range(len(right)):
    right_sum += int(right[i])

if(left_sum == right_sum):
    print("LUCKY")
else:
    print("READY")

