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
#define endl "\n"
using namespace std;

int N;
bool flag;
vector<vector<int> > graph;
int visited[101];

void DFS(int start, int destination) // start에서 destination으로 가는 경로가 있는지 확인한다.
{
    for(int i = 1; i <= N; i++)
    {
        if(graph[start][i] == 1 && visited[i] == 0) // 갈 수 있는 다음 노드가 있으면 이동
        {
            visited[i] = 1; // 방문 체크
            if(i == destination) // 그 다음 노드가 목적지면
                flag = true; // flag를 true로 바꾼다.
            else // 아니면
                DFS(i, destination); // destination은 고정하고 시작점은 현위치로 바꾼 채 DFS를 마저 진행한다.
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    graph.assign(N + 1, vector<int>(N + 1));

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> graph[i][j];
        }
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            flag = false;
            memset(visited, 0, sizeof(visited));
            DFS(i, j); // i에서 j로의 경로가 있는지 확인한다.
            if(flag) // 경로가 있으면
                cout << 1 << " "; // 1을 그 자리에서 출력하고
            else // 경로가 없으면
                cout << 0 << " "; // 0을 그 자리에서 출력한다.
        }
        cout << endl;
    }
    
	return 0;
}