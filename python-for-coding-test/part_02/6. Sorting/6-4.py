import sys
input = sys.stdin.readline

N, K = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort()
B.sort(reverse=True)

def swap(i):
    temp = A[i]
    A[i] = B[i]
    B[i] = temp

for i in range(K):
    if(A[i] < B[i]):
        swap(i)

print(sum(A))