def count_smaller_or_equal(mid, n):
    count = 0
    for i in range(1, n + 1):
        count += min(mid // i, n)
    return count

def kth_number(n, k):
    start, end = 1, k
    result = 0

    while start <= end:
        mid = (start + end) // 2
        count = count_smaller_or_equal(mid, n)

        if count >= k:
            result = mid
            end = mid - 1
        else:
            start = mid + 1
    
    return result

n = int(input())
k = int(input())

print(kth_number(n, k))
