#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>
#include <climits>
#include <deque>
#include <stack>
using namespace std;
void Init()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}

struct Point{
	int x;
	int y;
};

int t, n;
int visited[103];
void input();
void dfs();
void output();
vector<Point> dests;
stack<Point> s;

void input()
{
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		memset(visited, 0, sizeof(visited));
		dests.clear();
		while(!s.empty())
		{
			s.pop();
		}
		cin >> n;
		Point home;
		cin >> home.x >> home.y;
		s.push(home);
		for(int j = 0; j < n; j++)
		{
			Point conv;
			cin >> conv.x >> conv.y;
			dests.push_back(conv);
		}
		Point festival;
		cin >> festival.x >> festival.y;
		dests.push_back(festival);

		dfs();
		output();
	}
}

void output()
{
	if(visited[n])
		cout << "happy" << endl;
	else
		cout << "sad" << endl;
}

void dfs()
{
	while(!s.empty())
	{
		Point cur = s.top();
		s.pop();
		int cur_x = cur.x;
		int cur_y = cur.y;
		if(visited[n])
			break;
		for(int i = 0; i < dests.size(); i++)
		{
			if(!visited[i])
			{
				Point next = dests[i];
				int nx = next.x;
				int ny = next.y;
				if(abs(cur_x - nx) + abs(cur_y - ny) <= 1000)
				{
					s.push(next);
					visited[i] = 1;
				}
			}
		}
	}
}

int main()
{
    Init();
	input();

	return 0;
}