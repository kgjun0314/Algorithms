#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>
#include <climits>
#include <deque>
using namespace std;

struct SnakeBody{
	int r;
	int c;
};

int N, K, L, X, seconds = 0;
int snakeHead_r = 1, snakeHead_c = 1;
bool endFlag = false, eatenApple = false;
string C;
int _map[101][101];
string direction[10001];
deque<SnakeBody> snake;
int directionNumber = 0;
int directionOfSnake[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1 ,0}}; 

void input();
void move();
bool isValid(int r, int c);
void moveHead();
void moveTail();
bool isCrashed();

bool isValid(int r, int c)
{
	return (1 <= r && r <= N && 1 <= c && c <= N);
}

void moveHead()
{
	SnakeBody sb = snake.back();
	int nr = sb.r + directionOfSnake[directionNumber][0];
	int nc = sb.c + directionOfSnake[directionNumber][1];
	if(!isValid(nr, nc))
		endFlag = true;
	else
	{
		SnakeBody newHead;
		newHead.r = nr;
		newHead.c = nc;
		snake.push_back(newHead);
		if(_map[nr][nc] == 1)
		{
			_map[nr][nc] = 0;
			eatenApple = true;
		}
		else
			eatenApple = false;
	}
}

void moveTail()
{
	if(eatenApple)
	{
		return;
	}
	else
	{
		snake.pop_front();
	}
}

bool isCrashed()
{
	SnakeBody sb = snake.back();
	int snakeHead_r = sb.r;
	int snakeHead_c = sb.c;
	for(int i = 0; i < snake.size() - 1; i++)
	{
		if(snakeHead_r == snake[i].r && snakeHead_c == snake[i].c)
            return true;
	}
	return false;
}

void move()
{
	while(!endFlag)
	{	
		seconds++;
		moveHead();
		if(isCrashed())
			endFlag = true;
		if(endFlag)
			break;
		moveTail();
		if(direction[seconds] == "D" || direction[seconds] == "L")
		{
			if(direction[seconds] == "D")
			{
				directionNumber++;
				directionNumber = directionNumber % 4;
			}
			else
			{
				directionNumber--;
				if(directionNumber == -1)
					directionNumber = 3;
			}
		}

		if(isCrashed())
			endFlag = true;
		if(endFlag)
			break;
	}
}

void input()
{
	cin >> N;
	cin >> K;

	memset(_map, 0, sizeof(_map));
	memset(direction, 0, sizeof(direction));

	for(int i = 0; i < K; i++)
	{
		int r;
		int c;
		cin >> r >> c;
		_map[r][c] = 1;
	}

	cin >> L;

	for(int i = 0; i < L; i++)
	{
		cin >> X >> C;
		direction[X] = C;
	}

	SnakeBody sb;
	sb.r = snakeHead_r;
	sb.c = snakeHead_c;
	snake.push_back(sb);
}

int main()
{
    cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	input();

	move();

	cout << seconds << endl;

	return 0;
}