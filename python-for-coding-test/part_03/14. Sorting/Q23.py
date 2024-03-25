import sys
input = sys.stdin.readline

N = int(input())

students = []

for i in range(N):
    name, korean, english, math = input().split()
    students.append((name, int(korean), int(english), int(math)))

students.sort(key = lambda x: (-x[1], x[2], -x[3], x[0]))

for student in students:
    print(student[0])