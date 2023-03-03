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
int num;
set<string> s;
string str;

string slide(int a, int b)
{
	return string(str.begin() + a, str.begin()+ b + 1);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> str;

	for(int i = 0; i < str.length(); i++)
	{
		for(int j = i; j < str.length(); j++)
		{
			s.insert(slide(i, j));
		}
	}

	cout << s.size() << endl; 

    return 0;
}