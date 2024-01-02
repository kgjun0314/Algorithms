#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define endl "\n";

int M, N;
int graph[501][501];
int ans;
int DP[501][501];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool isValid(int y, int x)  // 유효 범위 체크
{
    if(y < 0 || x < 0 || y >= M || x >= N)
        return false;
    return true;
}

int DFS(int y, int x)
{
    if(y == M - 1 && x == N - 1)    // 목적지 도착시 return 1
        return 1;

    if(DP[y][x] != -1)  // DP값 존재하면 DP값 return
        return DP[y][x];

    DP[y][x] = 0;

    for(int i = 0; i < 4; i++)  // 상하좌우 보면서 DP값 갱신
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(isValid(ny, nx))
        {
            if(graph[ny][nx] < graph[y][x])
            {
                DP[y][x] = DP[y][x] + DFS(ny, nx);
            }
        }
    }
    return DP[y][x];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            DP[i][j] = -1;
            cin >> graph[i][j];
        }
    }

    ans = DFS(0, 0);

    cout << ans << endl;

    return 0;
}