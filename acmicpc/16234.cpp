#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

struct Point{
	int y;
	int x;
};
int N, L, R;
int A[51][51];
int temp[51][51];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int visited[51][51];
queue<Point> q;

bool isValid(int y, int x)
{
	return (0 <= y && y < N && 0 <= x && x < N && !visited[y][x]);
}

int BFS()
{
	int sum_union = 0;
	int divide = 0;
	int flag = 0;
	vector<Point> v;

	while(!q.empty())
	{
		Point cur = q.front();
		sum_union += A[cur.y][cur.x];
		v.push_back(cur);
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			Point next;
			next.y = cur.y + dy[i];
			next.x = cur.x + dx[i];
			if(isValid(next.y, next.x))
			{
				int diff = abs(A[cur.y][cur.x] - A[next.y][next.x]);
				if(diff >= L && diff <= R)
				{
					visited[next.y][next.x] = 1;
					flag = 1;
					q.push(next);
				}
			}
		}
	}

	divide = sum_union / v.size();

	for(int i = 0; i < v.size(); i++)
	{
		Point temp_point = v[i];
		temp[temp_point.y][temp_point.x] = divide;
	}

	return flag;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N >> L >> R;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> A[i][j];
			temp[i][j] = A[i][j];
		}
	}

	int cnt = 0;

	while(1)
	{
		memset(visited, 0, sizeof(visited));
		int flag = 0;

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				if(!visited[i][j])
				{
					visited[i][j] = 1;
					Point cur = Point();
					cur.y = i;
					cur.x = j;
					q.push(cur);
					flag += BFS();
				}
			}
		}

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				A[i][j] = temp[i][j];
			}
		}

		if(!flag)
		{
			cout << cnt << endl;
			break;
		}
		cnt++;
	}
	
    return 0;
}