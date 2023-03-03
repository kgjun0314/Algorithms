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

int N, M, cnt = 0;
string str;
set<string> strs;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		cin >> str;
		strs.insert(str);
	}

	for(int i = 0; i < M; i++)
	{
		cin >> str;
		if(strs.find(str) != strs.end())
		{
			cnt++;
		}
	}
	
	cout << cnt << endl;

    return 0;
}