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

vector<int> v;

void solve(int start, int end)
{
	if(start > end)
	{
		return;
	}

	int root = v[start];
	int idx = start + 1;

	while(idx <= end && v[idx] < root)
	{
		idx++;
	}

	solve(start + 1, idx - 1);
	solve(idx, end);
	cout << root << endl;

}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
	int n;
	while(cin >> n)
	{
		v.push_back(n);
	}

	solve(0, v.size() - 1);

    return 0;
}