import sys
input = sys.stdin.readline

def bs(data, low, high):
    mid = (low + high) // 2
    if low > high:
        return -1;
    if(data[mid] == mid):   
        return mid;
    elif(mid > data[mid]):
        return bs(data, mid + 1, high)
    else:
        return bs(data, low, mid - 1)

N = int(input())

data = list(map(int, input().split()))

print(bs(data, 0, N))
