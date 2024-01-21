#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>
#include <climits>
using namespace std;

int gears[4][8];
int isRotated[4];
string G;
int K, gear, direction;
int score = 0;
void CCR(int, int, int);
void CR(int, int, int);


bool isValid(int gear)
{
	return (0 <= gear && gear <= 3); 
}

void CCR(int gear, int left, int right)
{
	if(isValid(gear - 1)) // gear 기준 왼쪽거 돌리는거
	{
		if(!isRotated[gear - 1] && left != gears[gear - 1][2])
		{
			int curLeft = gears[gear - 1][6];
			int curRight = gears[gear - 1][2];
			isRotated[gear - 1] = 1;
			int temp[8];
			temp[7] = gears[gear - 1][0];
			for(int i = 0; i < 7; i++)
			{
				temp[i] = gears[gear - 1][i + 1];
			}
			for(int i = 0; i < 8; i++)
			{
				gears[gear - 1][i] = temp[i];
			}
			CR(gear - 1, curLeft, curRight);
		}
	}
	if(isValid(gear + 1))
	{
		if(!isRotated[gear + 1] && right != gears[gear + 1][6])
		{
			int curLeft = gears[gear + 1][6];
			int curRight = gears[gear + 1][2];
			isRotated[gear + 1] = 1;
			int temp[8];
			temp[7] = gears[gear + 1][0];
			for(int i = 0; i < 7; i++)
			{
				temp[i] = gears[gear + 1][i + 1];
			}
			for(int i = 0; i < 8; i++)
			{
				gears[gear + 1][i] = temp[i];
			}
			CR(gear + 1, curLeft, curRight);
		}
	}
}

void CR(int gear, int left, int right)
{
	if(isValid(gear - 1)) // gear 기준 왼쪽거 돌리는거
	{
		if(!isRotated[gear - 1] && left != gears[gear - 1][2])
		{
			int curLeft = gears[gear - 1][6];
			int curRight = gears[gear - 1][2];
			isRotated[gear - 1] = 1;
			int temp[8];
			temp[0] = gears[gear - 1][7];
			for(int i = 1; i < 8; i++)
			{
				temp[i] = gears[gear - 1][i - 1];
			}
			for(int i = 0; i < 8; i++)
			{
				gears[gear - 1][i] = temp[i];
			}
			CCR(gear - 1, curLeft, curRight);
		}
	}
	if(isValid(gear + 1))
	{
		if(!isRotated[gear + 1] && right != gears[gear + 1][6])
		{
			int curLeft = gears[gear + 1][6];
			int curRight = gears[gear + 1][2];
			isRotated[gear + 1] = 1;
			int temp[8];
			temp[0] = gears[gear + 1][7];
			for(int i = 1; i < 8; i++)
			{
				temp[i] = gears[gear + 1][i - 1];
			}
			for(int i = 0; i < 8; i++)
			{
				gears[gear + 1][i] = temp[i];
			}
			CCR(gear + 1, curLeft, curRight);
		}
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	for(int i = 0; i < 4; i++)
	{
		cin >> G;
		for(int j = 0; j < 8; j++)
		{
			gears[i][j] = G[j] - '0';
		}
	}

	cin >> K;

	for(int i = 0; i < K; i++)
	{
		memset(isRotated, 0, sizeof(isRotated));
		cin >> gear >> direction;
		int left = gears[gear - 1][6];
		int right = gears[gear - 1][2];
		isRotated[gear - 1] = 1;
		if(direction == 1) // 시계
		{
			int temp[8];
			temp[0] = gears[gear - 1][7];
			for(int i = 1; i < 8; i++)
			{
				temp[i] = gears[gear - 1][i - 1];
			}
			for(int i = 0; i < 8; i++)
			{
				gears[gear - 1][i] = temp[i];
			}
			CCR(gear - 1, left, right); // 옆에거 반시계
		}
		else
		{
			int temp[8];
			temp[7] = gears[gear - 1][0];
			for(int i = 0; i < 7; i++)
			{
				temp[i] = gears[gear - 1][i + 1];
			}
			for(int i = 0; i < 8; i++)
			{
				gears[gear - 1][i] = temp[i];
			}
			CR(gear - 1, left, right);
		}
	}

	for(int i = 0; i < 4; i++)
	{
		if(gears[i][0] == 1)
		{
			if(i == 0)
				score += 1;
			else if(i == 1)
				score += 2;
			else if(i == 2)
				score += 4;
			else if(i == 3)
				score += 8;
		}
	}

	cout << score << endl;

    return 0;
}