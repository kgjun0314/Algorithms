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
#define endl "\n"
using namespace std;

int N;
string str;
vector<vector<string> > v(51);

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		bool same = false;
		cin >> str;
		for(int j = 0; j < v[str.length()].size(); j++)
		{
			if(v[str.length()][j] == str)
			{
				same = true;
				break;
			}
		}
		if(same)
		{
			continue;
		}
		v[str.length()].push_back(str);
	}

	for(int i = 0; i < v.size(); i++)
	{
		sort(v[i].begin(), v[i].end());
	}

	for(auto i : v)
	{
		for(auto s : i)
		{
			cout << s << endl;
		}
	}

    return 0;
}