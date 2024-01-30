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

int N, M, Max = INT_MIN;
int Map[501][501];

void input();
void cal1();
void cal2();
void cal3();
void cal4();
void cal5();

void input()
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
		}
	}
}

void cal1()
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M - 3; j++)
		{
			int temp = Map[i][j] + Map[i][j + 1] + Map[i][j + 2] + Map[i][j + 3];
			if(temp > Max)
				Max = temp;
		}
	}

	for(int i = 0; i < N - 3; i++)
	{
		for(int j = 0; j < M; j++)
		{
			int temp = Map[i][j] + Map[i + 1][j] + Map[i + 2][j] + Map[i + 3][j];
			if(temp > Max)
				Max = temp;
		}
	}
}

void cal2()
{
	for(int i = 0; i < N - 1; i++)
	{
		for(int j = 0; j < M - 1; j++)
		{
			int temp = Map[i][j] + Map[i + 1][j] + Map[i][j + 1] + Map[i + 1][j + 1];
			if(temp > Max)
				Max = temp;
		}
	}
}

void cal3()
{
	for(int i = 0; i < N - 2; i++)
	{
		for(int j = 0; j < M - 1; j++)
		{
			int temp = Map[i][j] + Map[i + 1][j] + Map[i + 2][j] + Map[i + 2][j + 1];
			if(temp > Max)
				Max = temp;
		}
	}
	for(int i = 0; i < N - 1; i++)
	{
		for(int j = 0; j < M - 2; j++)
		{
			int temp = Map[i][j] + Map[i][j + 1] + Map[i][j + 2] + Map[i + 1][j];
			if(temp > Max)
				Max = temp;
		}
	}
	for(int i = 0; i < N - 2; i++)
	{
		for(int j = 0; j < M - 1; j++)
		{
			int temp = Map[i][j] + Map[i][j + 1] + Map[i + 1][j + 1] + Map[i + 2][j + 1];
			if(temp > Max)
				Max = temp;
		}
	}
	for(int i = 0; i < N - 1; i++)
	{
		for(int j = 0; j < M - 2; j++)
		{
			int temp = Map[i + 1][j] + Map[i + 1][j + 1] + Map[i + 1][j + 2] + Map[i][j + 2];
			if(temp > Max)
				Max = temp;
		}
	}

	for(int i = 0; i < N - 2; i++)
	{
		for(int j = 0; j < M - 1; j++)
		{
			int temp = Map[i][j + 1] + Map[i + 1][j + 1] + Map[i + 2][j + 1] + Map[i + 2][j];
			if(temp > Max)
				Max = temp;
		}
	}
	for(int i = 0; i < N - 1; i++)
	{
		for(int j = 0; j < M - 2; j++)
		{
			int temp = Map[i][j] + Map[i + 1][j] + Map[i + 1][j + 1] + Map[i + 1][j + 2];
			if(temp > Max)
				Max = temp;
		}
	}
	for(int i = 0; i < N - 2; i++)
	{
		for(int j = 0; j < M - 1; j++)
		{
			int temp = Map[i][j] + Map[i][j + 1] + Map[i + 1][j] + Map[i + 2][j];
			if(temp > Max)
				Max = temp;
		}
	}
	for(int i = 0; i < N - 1; i++)
	{
		for(int j = 0; j < M - 2; j++)
		{
			int temp = Map[i][j] + Map[i][j + 1] + Map[i][j + 2] + Map[i + 1][j + 2];
			if(temp > Max)
				Max = temp;
		}
	}
}

void cal4()
{
	for(int i = 0; i < N - 2; i++)
	{
		for(int j = 0; j < M - 1; j++)
		{
			int temp = Map[i][j] + Map[i + 1][j] + Map[i + 1][j + 1] + Map[i + 2][j + 1];
			if(temp > Max)
				Max = temp;
		}
	}
	for(int i = 0; i < N - 1; i++)
	{
		for(int j = 0; j < M - 2; j++)
		{
			int temp = Map[i + 1][j] + Map[i + 1][j + 1] + Map[i][j + 1] + Map[i][j + 2];
			if(temp > Max)
				Max = temp;
		}
	}

	for(int i = 0; i < N - 2; i++)
	{
		for(int j = 0; j < M - 1; j++)
		{
			int temp = Map[i][j + 1] + Map[i + 1][j + 1] + Map[i + 1][j] + Map[i + 2][j];
			if(temp > Max)
				Max = temp;
		}
	}
	for(int i = 0; i < N - 1; i++)
	{
		for(int j = 0; j < M - 2; j++)
		{
			int temp = Map[i][j] + Map[i][j + 1] + Map[i + 1][j + 1] + Map[i + 1][j + 2];
			if(temp > Max)
				Max = temp;
		}
	}
}

void cal5()
{
	for(int i = 0; i < N - 1; i++)
	{
		for(int j = 0; j < M - 2; j++)
		{
			int temp = Map[i][j] + Map[i][j + 1] + Map[i + 1][j + 1] + Map[i][j + 2];
			if(temp > Max)
				Max = temp;
		}
	}
	for(int i = 0; i < N - 2; i++)
	{
		for(int j = 0; j < M - 1; j++)
		{
			int temp = Map[i][j + 1] + Map[i + 1][j + 1] + Map[i + 1][j] + Map[i + 2][j + 1];
			if(temp > Max)
				Max = temp;
		}
	}
	for(int i = 0; i < N - 1; i++)
	{
		for(int j = 0; j < M - 2; j++)
		{
			int temp = Map[i + 1][j] + Map[i + 1][j + 1] + Map[i][j + 1] + Map[i + 1][j + 2];
			if(temp > Max)
				Max = temp;
		}
	}
	for(int i = 0; i < N - 2; i++)
	{
		for(int j = 0; j < M - 1; j++)
		{
			int temp = Map[i][j] + Map[i + 1][j] + Map[i + 1][j + 1] + Map[i + 2][j];
			if(temp > Max)
				Max = temp;
		}
	}
}

int main()
{
    cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	input();

	cal1();
	cal2();
	cal3();
	cal4();
	cal5();

	cout << Max << endl;

	return 0;
}