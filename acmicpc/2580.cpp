#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <sstream>
#include <cmath>
#include <cstdlib>
#define endl "\n"
using namespace std;

int arr[9][9];
int cnt[10];
bool flag = true;

void print()
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

bool check(int row, int column)
{
	memset(cnt, 0, sizeof(cnt)); 
	for(int drow = 0; drow < 9; drow++)
	{
		if(arr[drow][column] != 0)
		{
			cnt[arr[drow][column]] += 1;
		}
		if(cnt[arr[drow][column]] >= 2)
		{
			return false;
		}
	}

	memset(cnt, 0, sizeof(cnt)); 
	for(int dcolumn = 0; dcolumn < 9; dcolumn++)
	{
		if(arr[row][dcolumn] != 0)
		{
			cnt[arr[row][dcolumn]] += 1;
		}
		if(cnt[arr[row][dcolumn]] >= 2)
		{
			return false;
		}
	}

	memset(cnt, 0, sizeof(cnt)); 
	if(row >= 0 && row <= 2)
	{
		if(column >= 0 && column <= 2)
		{
			for(int i = 0; i <= 2; i++)
			{
				for(int j = 0; j <= 2; j++)
				{
					if(arr[i][j] != 0)
					{
						cnt[arr[i][j]] += 1;
					}
					if(cnt[arr[i][j]] >= 2)
					{
						return false;
					}
				}
			}
		}
		if(column >= 3 && column <= 5)
		{
			for(int i = 0; i <= 2; i++)
			{
				for(int j = 3; j <= 5; j++)
				{
					if(arr[i][j] != 0)
					{
						cnt[arr[i][j]] += 1;
					}
					if(cnt[arr[i][j]] >= 2)
					{
						return false;
					}
				}
			}
		}
		if(column >= 6 && column <= 8)
		{
			for(int i = 0; i <= 2; i++)
			{
				for(int j = 6; j <= 8; j++)
				{
					if(arr[i][j] != 0)
					{
						cnt[arr[i][j]] += 1;
					}
					if(cnt[arr[i][j]] >= 2)
					{
						return false;
					}
				}
			}			
		}
	}

	if(row >= 3 && row <= 5)
	{
		if(column >= 0 && column <= 2)
		{
			for(int i = 3; i <= 5; i++)
			{
				for(int j = 0; j <= 2; j++)
				{
					if(arr[i][j] != 0)
					{
						cnt[arr[i][j]] += 1;
					}
					if(cnt[arr[i][j]] >= 2)
					{
						return false;
					}
				}
			}
		}
		if(column >= 3 && column <= 5)
		{
			for(int i = 3; i <= 5; i++)
			{
				for(int j = 3; j <= 5; j++)
				{
					if(arr[i][j] != 0)
					{
						cnt[arr[i][j]] += 1;
					}
					if(cnt[arr[i][j]] >= 2)
					{
						return false;
					}
				}
			}
		}
		if(column >= 6 && column <= 8)
		{
			for(int i = 3; i <= 5; i++)
			{
				for(int j = 6; j <= 8; j++)
				{
					if(arr[i][j] != 0)
					{
						cnt[arr[i][j]] += 1;
					}
					if(cnt[arr[i][j]] >= 2)
					{
						return false;
					}
				}
			}			
		}
	}

	if(row >= 6 && row <= 8)
	{
		if(column >= 0 && column <= 2)
		{
			for(int i = 6; i <= 8; i++)
			{
				for(int j = 0; j <= 2; j++)
				{
					if(arr[i][j] != 0)
					{
						cnt[arr[i][j]] += 1;
					}
					if(cnt[arr[i][j]] >= 2)
					{
						return false;
					}
				}
			}
		}
		if(column >= 3 && column <= 5)
		{
			for(int i = 6; i <= 8; i++)
			{
				for(int j = 3; j <= 5; j++)
				{
					if(arr[i][j] != 0)
					{
						cnt[arr[i][j]] += 1;
					}
					if(cnt[arr[i][j]] >= 2)
					{
						return false;
					}
				}
			}
		}
		if(column >= 6 && column <= 8)
		{
			for(int i = 6; i <= 8; i++)
			{
				for(int j = 6; j <= 8; j++)
				{
					if(arr[i][j] != 0)
					{
						cnt[arr[i][j]] += 1;
					}
					if(cnt[arr[i][j]] >= 2)
					{
						return false;
					}
				}
			}			
		}
	}

	return true;
}

bool nozero()
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			if(arr[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

void solve()
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			if(arr[i][j] == 0)
			{
				for(int k = 1; k <= 9; k++)
				{
					arr[i][j] = k;
					if(check(i, j))
					{
						solve();
					}
					arr[i][j] = 0;
				}
				return;
			}
			if(i == 8 && j == 8)
			{
				if(nozero())
				{
					print();
					exit(0);
				}
			}
		}
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	solve();

    return 0;
}
