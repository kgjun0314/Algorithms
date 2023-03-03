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

int N, M;
string name;
string nameorid;
map<int, string> m;
map<string, int> m2;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N >> M;

	for(int i = 1; i <= N; i++)
	{
		cin >> name;
		m.insert(make_pair(i, name));
		m2.insert(make_pair(name, i));
	}

	for(int i = 0; i < M; i++)
	{
		cin >> nameorid;
		if(isdigit(nameorid[0]))
		{
			int idx = stoi(nameorid);
			cout << m[idx] << endl;
		}
		else
		{
			cout << m2[nameorid] << endl;
		}
	}

    return 0;
}