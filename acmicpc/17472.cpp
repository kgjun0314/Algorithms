#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <tuple>
#include <queue>
#include <cstring>
#define endl "\n"
using namespace std;

int N, M, numOfIsland = 0, ans = 0;
int parent[7];
int Graph[7][7];
int Map[11][11];
int visitedGraph[11][11];
int distGraph[7][7];
int visited[7];
vector<pair<pair<int, int>, int> > v;
queue<int> q;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1}; 


void DFS(int y, int x);
void distance(int cur, int y, int x);
bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b);
int Find(int a);
int Union(int a, int b);

int Find(int a)
{
    if(parent[a] == a)
        return a;
    else
        return parent[a] = Find(parent[a]);
}

int Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if(a < b)
    {
        parent[b] = a;
        Graph[a][b] = 1;
        Graph[b][a] = 1;
        return 1;
    }
    else if(a > b)
    {
        parent[a] = b;
        Graph[a][b] = 1;
        Graph[b][a] = 1;
        return 1;
    }
    return 0;
}

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.second <= b.second;
}

void DFS(int y, int x)
{
    if(visitedGraph[y][x])
        return;
    
    visitedGraph[y][x] = 1;
    Map[y][x] = numOfIsland;

    for(int i = 0; i < 4; i++)
    {
        int next_y = y + dy[i];
        int next_x = x + dx[i];

        if(next_x >= 1 && next_x <= M && next_y >= 1 && next_y <= N)
        {
            if(Map[next_y][next_x] != 0 && !visitedGraph[next_y][next_x])
                DFS(next_y, next_x);
        }
    }
}

void distance(int cur, int y, int x)
{
    for(int i = 0; i < 4; i++)
    {
        int cur_y = y;
        int cur_x = x;
        int dist = 0;

        while(true)
        {
            cur_y += dy[i];
            cur_x += dx[i];

            if(cur_x < 1 || cur_x > M || cur_y < 1 || cur_y > N || Map[cur_y][cur_x] == cur)
                break;
            
            if(Map[cur_y][cur_x] != 0)
            {
                if(distGraph[cur][Map[cur_y][cur_x]] == 0 && dist > 1)
                {
                    distGraph[cur][Map[cur_y][cur_x]] = dist;
                    distGraph[Map[cur_y][cur_x]][cur] = dist;
                }
                else if(distGraph[cur][Map[cur_y][cur_x]] >= dist && dist > 1)
                {
                    distGraph[cur][Map[cur_y][cur_x]] = dist;
                    distGraph[Map[cur_y][cur_x]][cur] = dist;
                }
                break;
            }

            dist++;
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(visitedGraph, 0, sizeof(visitedGraph));
    memset(distGraph, 0, sizeof(distGraph));
    memset(Graph, 0, sizeof(Graph));
    memset(visited, 0, sizeof(visited));

    cin >> N >> M;

    for(int i = 1; i <= 6; i++)
    {
        parent[i] = i;
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            cin >> Map[i][j];
        }
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if(Map[i][j] != 0)
            {
                if(!visitedGraph[i][j])
                    numOfIsland++;
                DFS(i, j);
            }
        }
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if(Map[i][j] != 0)
            {
                distance(Map[i][j], i, j);
            }
        }
    }

    for(int i = 1; i <= 6; i++)
    {
        for(int j = i; j <= 6; j++)
        {
            if(distGraph[i][j] != 0)
            {
                v.push_back(make_pair(make_pair(i, j), distGraph[i][j]));
            }
        }
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < v.size(); i++)
    {
        int dist = v[i].second;
        int islandA = v[i].first.first;
        int islandB = v[i].first.second;

        if(Union(islandA, islandB))
            ans += dist;
    }

    int cnt = 1;
    q.push(1);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        visited[cur] = true;

        for(int i = 0; i < 7; i++)
        {
            int next = Graph[cur][i];
            if(next == 1 && !visited[i])
            {
                q.push(i);
                cnt++;
            }
        }
    }

    if(numOfIsland == cnt)
        cout << ans << endl;
    else
        cout << -1 << endl;

    return 0;
}