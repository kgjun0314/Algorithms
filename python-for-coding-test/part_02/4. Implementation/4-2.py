input_data = input();
y = int(input_data[1]);
x = int(ord(input_data[0]) - ord('a')) + 1

moveset = [[-2, -1], [-2, 1], [2, -1], [2, 1], [-1, -2], [-1, 2], [1, -2], [1, 2]]

def is_valid(y, x):
    return (1 <= y and y <= 8 and 1 <= x and x <= 8);

answer = 0

for i in range(len(moveset)):
    ny = y + moveset[i][0]
    nx = x + moveset[i][1]
    if(is_valid(ny, nx)):
        answer += 1

print(answer)