import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

parent = {}
number = {}

def Find(x):
    if parent[x] != x:
        parent[x] = Find(parent[x])
    return parent[x]

def Union(a, b):
    pa = Find(a)
    pb = Find(b)

    if pa != pb:
        parent[pb] = pa
        number[pa] += number[pb]
    print(number[pa])

for i in range(int(input())):
    F = int(input())
    parent, number = {}, {}
    for j in range(F):
        A, B = input().split()
        if A not in parent:
            parent[A] = A
            number[A] = 1
        if B not in parent:
            parent[B] = B
            number[B] = 1
        Union(A, B)