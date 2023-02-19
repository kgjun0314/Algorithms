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
#include <cstdlib>
#include <cmath>
#define endl "\n"
using namespace std;

int N;
int arr[16][16];
int result = 0;

bool check(int row, int column)
{
	for(int drow = 0; drow < row; drow++)
	{
		if(arr[drow][column] == 1)
		{
			return false;
		}
	}

	int drow = row;
	int dcolumn = column;
	while(drow >= 0 && dcolumn >= 0)
	{
		if(arr[drow][dcolumn] == 1)
		{
			return false;
		}
		drow--;
		dcolumn--;
	}

	drow = row;
	dcolumn = column;
	while(drow >= 0 && dcolumn <= N - 1)
	{
		if(arr[drow][dcolumn] == 1)
		{
			return false;
		}
		drow--;
		dcolumn++;
	}

	return true;
}

void backtracking(int row)
{
	if(row == N)
	{
		result++;
		return;
	}
	for(int column = 0; column < N; column++)
	{
		if(check(row, column))
		{
			arr[row][column] = 1;
			backtracking(row + 1);
			arr[row][column] = 0;
		}
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N;
	backtracking(0);

	cout << result << endl;

    return 0;
}
