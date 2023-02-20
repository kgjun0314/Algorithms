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
#include <cmath>
#include <cstdlib>
#define endl "\n"
using namespace std;

int a, n;
vector<int> v;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> n;
	while(n--)
	{
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	cout << v[0] * v[v.size() - 1] << endl;
	
    return 0;
}
