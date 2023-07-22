#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#define endl "\n"
using namespace std;

int N, M, A, B;
double X, Y, W = 0.0;
vector<pair<pair<int, int>, double> > graph;
vector<pair<int, int> > gods;
vector<int> v;

bool compare(pair<pair<int, int>, double> a, pair<pair<int, int>, double> b) 
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

void Union(int nodeA, int nodeB, double w, int flag)
{
    int pa = Find(v[nodeA]);
    int pb = Find(v[nodeB]);

    if(pa <= pb)
    {
        v[pb] = pa;
        if(flag == 1)
            W += w;
    }
    else
    {
        v[pa] = pb;
        if(flag == 1)
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

    for(int i = 1; i <= N; i++)
    {
        cin >> X >> Y;

        for(int j = 0; j < gods.size(); j++)
        {
            graph.push_back(make_pair(make_pair(i, j + 1), sqrt(pow(X - gods[j].first, 2) + pow(Y - gods[j].second, 2))));
        }

        gods.push_back(make_pair(X, Y));
    }

    sort(graph.begin(), graph.end(), compare);

    for(int i = 0; i < M; i++)
    {
        cin >> A >> B;
        if(Find(A) != Find(B))
            Union(A, B, sqrt(pow(gods[A - 1].first - gods[B - 1].first, 2) + pow(gods[A - 1].second - gods[B - 1].second, 2)), 0);
    }

    for(int i = 0; i < graph.size(); i++)
    {
        if(Find(graph[i].first.first) != Find(graph[i].first.second))
        {
            Union(graph[i].first.first, graph[i].first.second, graph[i].second, 1);
        }
    }

    printf("%.2f\n", W);

    return 0;
}