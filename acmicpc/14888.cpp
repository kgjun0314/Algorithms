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

int MAX = -1000000001;
int MIN = 1000000001;
int N;
int arr[12];
int ope[4];
int val = 0;
int temp[12];

void cal(int num, int openum)
{
	if(openum == 0)
	{
		val += arr[num];
	}
	if(openum == 1)
	{
		val -= arr[num];
	}
	if(openum == 2)
	{
		val *= arr[num];
	}
	if(openum == 3)
	{
		val /= arr[num];
	}
}

void solve(int num, int openum)
{
	if(num == 0)
	{
		val = arr[0];
	}

	if(num > 0)
	{
		cal(num, openum);
	}

	if(num == N - 1)
	{
		if(val < MIN)
		{
			MIN = val;
		}
		if(val > MAX)
		{
			MAX = val;
		}
		return;
	}

	for(int i = 0; i < 4; i++)
	{
		if(ope[i] > 0)
		{
			ope[i]--;
			temp[num] = val;
			solve(num + 1, i);
			ope[i]++;
			val = temp[num];
		}
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for(int i = 0; i < 4; i++)
	{
		cin >> ope[i];
	}

	solve(0, 0);

	cout << MAX << endl;
	cout << MIN << endl;

    return 0;
}
