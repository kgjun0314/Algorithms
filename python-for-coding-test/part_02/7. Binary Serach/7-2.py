import sys

N = int(sys.stdin.readline().rstrip())
store = list(map(int, sys.stdin.readline().split()))
M = int(sys.stdin.readline().rstrip())
requests = list(map(int, sys.stdin.readline().split()))

def binary_search(target, left, right):
    mid = (left + right) // 2
    if left > right:
        return False;
    
    if store[mid] == target:
        return True
    elif store[mid] < target:
        return binary_search(target, mid + 1, right)
    else:
        return binary_search(target, left, mid - 1)


store.sort();

for request in requests:
    flag = binary_search(request, 0, len(store) - 1)
    if flag == True:
        print("yes", end = " ")
    else:
        print("no", end = " ")