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
void Init()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int F, S, G, U, D;
int arr[1000001];
void input();

void input()
{
	cin >> F >> S >> G >> U >> D;
}

void dfs(int S, int cnt)
{
	arr[S] = cnt;
	if(S == G || cnt >= 1000001)
	{
		return;
	}
	if(S + U <= F && arr[S + U] > cnt + 1)
	{
		dfs(S + U, cnt + 1);
	}
	if(S - D > 0 && arr[S - D] > cnt + 1)
	{
		dfs(S - D, cnt + 1);
	}
}

int main()
{
	memset(arr, 1000001, sizeof(arr));
    Init();
	input();

	dfs(S, 0);

	if(arr[G] >= 1000001)
		cout << "use the stairs" << endl;
	else
		cout << arr[G] << endl;

	return 0;
}