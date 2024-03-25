def rotate(key):
    r = len(key)
    c = len(key[0])
    result = [[0 for i in range(c)] for j in range(r)]
    for i in range(r):
        for j in range(c):
            result[j][r - i - 1] = key[i][j]
    return result

def check(new_lock):
    lock_len = len(new_lock) // 3
    for i in range(lock_len, lock_len * 2):
        for j in range(lock_len, lock_len * 2):
            if(new_lock[i][j] != 1):
                return False
    return True

def solution(key, lock):
    n = len(lock)
    m = len(key)

    new_lock = [[0 for i in range(n * 3)] for j in range(n * 3)]

    for i in range(n):
        for j in range(n):
            new_lock[i + n][j + n] = lock[i][j]

    for rotation in range(4):
        key = rotate(key)
        for y in range(n * 2):
            for x in range(n * 2):
                for i in range(m):
                    for j in range(m):
                        new_lock[y + i][x + j] += key[i][j]
                if(check(new_lock) == True):
                    return True
                for i in range(m):
                    for j in range(m):
                        new_lock[y + i][x + j] -= key[i][j]

    return False

M, N = map(int, input().split())

key = []
lock = []
for _ in range(M):
    key.append(list(map(int, input().split())))

for _ in range(N):
    lock.append(list(map(int, input().split())))

sol = solution(key, lock)

if(sol == True):
    print("true")
else:
    print("false")