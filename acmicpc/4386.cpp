#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#define endl "\n"
using namespace std;

int n;
double x, y, W = 0.0;
vector<pair<pair<int, int>, double> > graph;
vector<pair<int, int> > stars;
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

void Union(int nodeA, int nodeB, double w)
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

    cin >> n;

    for(int i = 0; i <= n; i++)
    {
        v.push_back(i);
    }

    for(int i = 1; i <= n; i++)
    {
        cin >> x >> y;

        for(int j = 0; j < stars.size(); j++)
        {
            graph.push_back(make_pair(make_pair(i, j + 1), sqrt(pow(x - stars[j].first, 2) + pow(y - stars[j].second, 2))));
        }

        stars.push_back(make_pair(x, y));
    }

    sort(graph.begin(), graph.end(), compare);

    for(int i = 0; i < graph.size(); i++)
    {
        if(Find(graph[i].first.first) != Find(graph[i].first.second))
        {
            Union(graph[i].first.first, graph[i].first.second, graph[i].second);
        }
    }

    cout.precision(3);
    cout << W << endl;

    return 0;
}