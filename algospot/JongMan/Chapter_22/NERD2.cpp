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

int C, N, a, b;

map<int, int> coords;

bool isDominated(int x, int y)
{
	map<int, int>::iterator it = coords.lower_bound(x);
	if(it == coords.end())
	{
		return false;
	}
	return y < it->second;
}

void removeDominated(int x, int y)
{
	map<int, int>::iterator it = coords.lower_bound(x);
	if(it == coords.begin())
	{
		return;
	}
	it--;
	while(true)
	{
		if(it->second > y)
		{
			break;
		}
		if(it == coords.begin())
		{
			coords.erase(it); 
			break;
		}
		else
		{
			map<int, int>::iterator jt = it;
			jt--;
			coords.erase(it);
			it = jt;
		}
	}
}

int registered(int x, int y)
{
	if(isDominated(x, y))
	{
		return coords.size();
	}
	removeDominated(x, y);
	coords[x] = y;
	return coords.size();
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> C;

	while(C--)
	{
		int sum = 0;
		cin >> N;
		while(N--)
		{	
			cin >> a >> b;
			sum = sum + registered(a, b);
		}
		cout << sum << endl;
		coords.clear();
	}
    return 0;
}