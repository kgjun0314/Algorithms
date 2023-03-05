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
#include <cstdlib>
#include <set>
#define endl "\n"
using namespace std;

int T, n;
int x1, y1, x2, y2;
int cx, cy, r;
int sameparents;
vector<pair<pair<int, int>, int> > sp;
vector<pair<pair<int, int>, int> > ep;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> T;

	while(T--)
	{
		while(!sp.empty())
		{
			sp.pop_back();
		}
		while(!ep.empty())
		{
			ep.pop_back();
		}
		sameparents = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> cx >> cy >> r;
			if((cx - x1) * (cx - x1) + (cy - y1) * (cy - y1) < r * r)
			{
				sp.push_back(make_pair(make_pair(cx, cy), r));
			}
			if((cx - x2) * (cx - x2) + (cy - y2) * (cy - y2) < r * r)
			{
				ep.push_back(make_pair(make_pair(cx, cy), r));
			}
		}
		for(int i = 0; i < sp.size(); i++)
		{
			for(int j = 0; j < ep.size(); j++)
			{
				if(sp[i].first.first == ep[j].first.first && sp[i].first.second == ep[j].first.second && sp[i].second == ep[j].second)
				{
					sameparents++;
				}
			}
		}
		cout << sp.size() + ep.size() - sameparents * 2<< endl;
	}

    return 0;
}