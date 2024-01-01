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
#include <climits>
#define endl "\n"
using namespace std;

int N, cnt = 1;
vector<vector<int> > graph;
vector<vector<int> > dist;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool isValid(int y, int x)
{
    return (1 <= y && y <= N && 1 <= x && x <= N);
}

void BFS(int y, int x)
{
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    dist[1][1] = graph[1][1];

    while(!q.empty())
    {
        int cury = q.front().first;
        int curx = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nexty = cury + dy[i];
            int nextx = curx + dx[i];
            if(isValid(nexty, nextx))
            {
                if(dist[nexty][nextx] > dist[cury][curx] + graph[nexty][nextx])
                {
                    dist[nexty][nextx] = dist[cury][curx] + graph[nexty][nextx];
                    q.push(make_pair(nexty, nextx));
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

    while(cin >> N)
    {
        if(N == 0)
            break;
        graph.assign(N + 1, vector<int>(N + 1, 0));
        dist.assign(N + 1, vector<int>(N + 1, INT_MAX));
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                cin >> graph[i][j];
            }
        }

        BFS(1, 1);

        cout << "Problem " << cnt++ << ": " <<  dist[N][N] << endl;
    }

	return 0;
}