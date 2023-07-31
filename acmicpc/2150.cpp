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

int V, E, A, B, id, d[10001];
bool finished[10001];
vector<int> a[10001];
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

    cin >> V >> E;

    while(E--)
    {
        cin >> A >> B;
        a[A].push_back(B);
    }
    
    for(int i = 1; i <= V; i++)
    {
        if(d[i] == 0)
            dfs(i);
    }

    cout << SCC.size() << endl;
    for(int i = 0; i < SCC.size(); i++)
    {
        sort(SCC[i].begin(), SCC[i].end());
    }

    sort(SCC.begin(), SCC.end());

    for(int i = 0; i < SCC.size(); i++)
    {
        for(int j = 0; j < SCC[i].size(); j++)
        {
            cout << SCC[i][j] << " ";
        }
        cout << -1 << endl;
    }

    return 0;
}