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
#define endl "\n"
using namespace std;

int N, a, b;
vector<int> parent(100001);
vector<vector<int> > tree(100001);

void search_parent(int node)
{
	for(int i = 0; i < tree[node].size(); i++)
	{
		if(tree[node][i] == 1)
		{
			continue;
		}
		else if(parent[tree[node][i]] == 0)
		{
			parent[tree[node][i]] = node;
			search_parent(tree[node][i]);
		}
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N;

	for(int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	search_parent(1);

	for(int i = 2; i <= N; i++)
	{
		cout << parent[i] << endl;
	}

    return 0;
}