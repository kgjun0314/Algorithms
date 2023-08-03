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

int N, M, A, B, C, id, d[20002], group[20002], inDegree[20002];
bool ans = false;
bool finished[20002];
bool visited[20002];
int sign[20002];
vector<int> sorted;
vector<int> a[20002];
vector<int> scca[20002];
vector<vector<int> > SCC;
stack<int> s;
string Ac, Bc, Cc;

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
            if(find(scc.begin(), scc.end(), t + N) != scc.end() || find(scc.begin(), scc.end(), t - N) != scc.end())
            {
                cout << -1 << endl;
                exit(0);
            }
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

void topologicalSort()
{
    queue<int> q;

    for(int i = 1; i <= SCC.size(); i++)
    {
        if(inDegree[i] == 0)
            q.push(i);
    }

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        sorted.push_back(cur);

        for(int next : scca[cur])
        {
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

    cin >> N >> M;

    for(int i = 0; i < M; i++)
    {
        cin >> A >> Ac >> B >> Bc >> C >> Cc;
        if(Ac == "B" && Bc == "B" && Cc == "B")
        {
            a[N + A].push_back(B);
            a[N + B].push_back(A);

            a[N + B].push_back(C);
            a[N + C].push_back(B);

            a[N + C].push_back(A);
            a[N + A].push_back(C);
        }
        else if(Ac == "B" && Bc == "B" && Cc == "R")
        {
            a[N + A].push_back(B);
            a[N + B].push_back(A);

            a[N + B].push_back(N + C);
            a[C].push_back(B);

            a[C].push_back(A);
            a[N + A].push_back(N + C);
        }
        else if(Ac == "B" && Bc == "R" && Cc == "B")
        {
            a[N + A].push_back(N + B);
            a[B].push_back(A);

            a[B].push_back(C);
            a[N + C].push_back(N + B);

            a[N + C].push_back(A);
            a[N + A].push_back(C);
        }
        else if(Ac == "R" && Bc == "B" && Cc == "B")
        {
            a[A].push_back(B);
            a[N + B].push_back(N + A);

            a[N + B].push_back(C);
            a[N + C].push_back(B);

            a[N + C].push_back(N + A);
            a[A].push_back(C);
        }
        else if(Ac == "B" && Bc == "R" && Cc == "R")
        {
            a[N + A].push_back(N + B);
            a[B].push_back(A);

            a[B].push_back(N + C);
            a[C].push_back(N + B);

            a[C].push_back(A);
            a[N + A].push_back(N + C);
        }
        else if(Ac == "R" && Bc == "B" && Cc == "R")
        {
            a[A].push_back(B);
            a[N + B].push_back(N + A);

            a[N + B].push_back(N + C);
            a[C].push_back(B);

            a[C].push_back(N + A);
            a[A].push_back(N + C);
        }
        else if(Ac == "R" && Bc == "R" && Cc == "B")
        {
            a[A].push_back(N + B);
            a[B].push_back(N + A);

            a[B].push_back(C);
            a[N + C].push_back(N+ B);

            a[N + C].push_back(N + A);
            a[A].push_back(C);
        }
        else if(Ac == "R" && Bc == "R" && Cc == "R")
        {
            a[A].push_back(N + B);
            a[B].push_back(N + A);

            a[B].push_back(N + C);
            a[C].push_back(N + B);

            a[C].push_back(N + A);
            a[A].push_back(N + C);
        }
    }

    for(int i = 1; i <= 2 * N; i++)
    {
        if(d[i] == 0)
            dfs(i);
    }

    for(int i = 1; i <= 2 * N; i++)
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

    for(int i = 0; i < sorted.size(); i++)
    {
        for(int j = 0; j < SCC[sorted[i] - 1].size(); j++)
        {
            if(!visited[SCC[sorted[i] - 1][j]])
            {
                if(SCC[sorted[i] - 1][j] > N)
                {
                    visited[SCC[sorted[i] - 1][j]] = true;
                    sign[SCC[sorted[i] - 1][j]] = 0;
                    visited[SCC[sorted[i] - 1][j] - N] = true;
                    sign[SCC[sorted[i] - 1][j] - N] = 1;
                }
                else
                {
                    visited[SCC[sorted[i] - 1][j]] = true;
                    sign[SCC[sorted[i] - 1][j]] = 0;
                    visited[SCC[sorted[i] - 1][j] + N] = true;
                    sign[SCC[sorted[i] - 1][j] + N] = 1;
                }
            }
        }
    }

    for(int i = 1; i <= N; i++)
    {
        if(sign[i] == 0)
            cout << "R";
        else
            cout << "B";
    }

    cout << endl;

    return 0;
}