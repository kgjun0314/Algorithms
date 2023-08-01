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

int N, M, A, B, S, P, id, d[500002], cash[500002], group[500002], inDegree[500002], fromATM[500002], dp[500002];
bool finished[500002];
vector<int> scca[500002];
vector<int> a[500002];
vector<int> rest;
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
            group[t] = SCC.size();
            fromATM[SCC.size()] += cash[t];
            finished[t] = true;
            if(t == x)
                break;
        }
        SCC.push_back(scc);
    }

    return parent;
}

void topologicalSort()
{
    queue<int> q;

    for(int i = 1; i <= SCC.size(); i++)
    {
        if(inDegree[i] == 0)
            q.push(i);
    }

    dp[group[S]] = fromATM[group[S]];

    bool flag = false;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        if(cur == group[S])
            flag = true;
        
        for(int next : scca[cur])
        {
            if(flag)
                dp[next] = max(dp[next], dp[cur] + fromATM[next]);
            
            --inDegree[next];
            if(inDegree[next] == 0)
                q.push(next);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    SCC.push_back(vector<int>(0));

    cin >> N >> M;

    for(int i = 0; i < M; i++)
    {
        cin >> A >> B;
        a[A].push_back(B);
    }
    
    for(int i = 1; i <= N; i++)
    {
        cin >> cash[i];
    }

    cin >> S >> P;

    for(int i = 0; i < P; i++)
    {
        cin >> A;
        rest.push_back(A);
    }

    for(int i = 1; i <= N; i++)
    {
        if(d[i] == 0)
            dfs(i);
    }
    
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < a[i].size(); j++)
        {
            int y = a[i][j];
            if(group[i] != group[y])
            {
                scca[group[i]].push_back(group[y]);
                inDegree[group[y]]++;
            }
        }
    }    

    topologicalSort();

    int ans = 0;

    for(int i = 0; i < P; i++)
    {
        ans = max(ans, dp[group[rest[i]]]);
    }

    cout << ans << endl;

    return 0;
}