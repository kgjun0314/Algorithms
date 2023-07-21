#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define endl "\n"
using namespace std;

int T, N, M, A, B, C, W = 0;
vector<pair<pair<int, int>, int> > graph;
vector<int> v;

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) 
{
	return a.second < b.second;
}

int Find(int nodeA)
{
    if(v[nodeA] == nodeA)
        return nodeA;
    else
        return v[nodeA] = Find(v[nodeA]);
}

void Union(int nodeA, int nodeB, int w)
{
    int pa = Find(v[nodeA]);
    int pb = Find(v[nodeB]);

    if(pa <= pb)
    {
        v[pb] = pa;
        W += w;
    }
    else
    {
        v[pa] = pb;
        W += w;
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i <= N; i++)
    {
        v.push_back(i);
    }

    for(int i = 0; i < M; i++)
    {
        cin >> A >> B >> C;

        graph.push_back(make_pair(make_pair(A, B), C));
    }

    sort(graph.begin(), graph.end(), compare);

    for(int i = 0; i < graph.size(); i++)
    {
        if(Find(graph[i].first.first) != Find(graph[i].first.second))
        {
            Union(graph[i].first.first, graph[i].first.second, graph[i].second);
        }
    }

    cout << W << endl;

    return 0;
}