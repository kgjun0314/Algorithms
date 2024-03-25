import sys
input = sys.stdin.readline
from bisect import bisect_left, bisect_right

N, x = map(int, input().split())
data = list(map(int, input().split()))

answer = bisect_right(data, x) - bisect_left(data, x)

if answer != 0:
    print(bisect_right(data, x) - bisect_left(data, x))
else:
    print(-1)

