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

int N, M, A, B, id, d[20002];
string ans;
bool finished[20002];
int group[20002];
vector<int> a[20002];
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

    while(cin >> N >> M)
    {
        ans = "yes";
        id = 0;
        fill(d, d + 20002, 0);
        fill(group, group + 20002, 0);
        fill(finished, finished + 20002, 0);
        for(int i = 0; i < 20002; i++)
        {
            a[i].clear();
        }
        SCC.clear();

        for(int i = 0; i < M; i++)
        {
            cin >> A >> B;
            if(A > 0 && B > 0)
            {
                a[N + A].push_back(B);
                a[N + B].push_back(A);
            }
            else if(A > 0 && B < 0)
            {
                a[N + A].push_back(N + (-B));
                a[-B].push_back(A);
            }
            else if(A < 0 && B > 0)
            {
                a[-A].push_back(B);
                a[N + B].push_back(N + (-A));
            }
            else if(A < 0 && B < 0)
            {
                a[-A].push_back(N + (-B));
                a[-B].push_back(N + (-A));
            }
        }

        a[N + 1].push_back(1);

        for(int i = 1; i <= 2 * N; i++)
        {
            if(d[i] == 0)
                dfs(i);
        }

        for (int i = 1; i <= N; i++)
        {
            if (group[i] == group[i + N])
            {
                ans = "no";
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}