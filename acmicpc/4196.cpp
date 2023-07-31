#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <cmath>
#include <stack>
#define endl "\n";
using namespace std;

int T, N, M, x, y, id, d[100001];
bool finished[100001];
int group[100001];
int inDegree[100001];
vector<int> a[100001];
vector<vector<int> > SCC;
stack<int> s;

int dfs(int x)
{
    d[x] = ++id;
    s.push(x);

    int parent = d[x];
    for(int i = 0; i < a[x].size(); i++)
    {
        int y = a[x][i];
        if(d[y] == 0)
            parent = min(parent, dfs(y));
        else if(!finished[y])
            parent = min(parent, d[y]);
    }

    if(parent == d[x])
    {
        vector<int> scc;
        while(true)
        {
            int t = s.top();
            s.pop();
            scc.push_back(t);
            group[t] = SCC.size() + 1;
            finished[t] = true;
            if(t == x)
                break;
        }
        SCC.push_back(scc);
    }

    return parent;
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while(T--)
    {
        memset(d, 0, sizeof(d));
        fill(finished, finished + 100001, 0);
        memset(inDegree, 0, sizeof(inDegree));
        fill(group, group + 100001, 0);
        SCC.clear();
        id = 0;

        cin >> N >> M;

        for(int i = 1; i <= N; i++)
        {
            a[i].clear();
        }

        while(M--)
        {
            cin >> x >> y;
            a[x].push_back(y);
        }

        for(int i = 1; i <= N; i++)
            if(d[i] == 0)
                dfs(i);

        for(int i = 1; i <= N; i++)
        {
            for(int j = 0; j < a[i].size(); j++)
            {
                int y = a[i][j];
                if(group[i] != group[y])
                    inDegree[group[y]]++;
            }
        }
        int result = 0;
        for(int i = 1; i <= SCC.size(); i++)
        {
            if(inDegree[i] == 0)
                result++;
        }

        cout << result << endl;
    }

    return 0;
}