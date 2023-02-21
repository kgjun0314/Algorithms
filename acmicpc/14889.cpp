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

int MIN = 100;
int N;
int S[21][21];
int visited[21];
int start, link;

void solve(int cur, int cnt)
{
	if(cnt == N / 2)
	{
		start = 0;
		link = 0;
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				if(visited[i] && visited[j])
				{
					start += S[i][j];
				}
				if(!visited[i] && !visited[j])
				{
					link += S[i][j];
				}
			}
		}
		MIN = min(MIN, abs(start - link));
		return;
	}

	for(int i = cur; i <= N; i++)
	{
		visited[i] = 1;
	 	solve(i + 1, cnt + 1);
		visited[i] = 0;
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	memset(visited, 0, sizeof(visited));

	cin >> N;

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> S[i][j];
		}
	}

	solve(1, 0);

	cout << MIN << endl;
	
    return 0;
}
