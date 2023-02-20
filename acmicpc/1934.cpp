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

int n, a, b;

int gcd(int a, int b)
{
	if(a == b)
	{
		return a;
	}

	if(a < b)
	{
		return gcd(b, a);
	}
	if(a > b)
	{
		return gcd(a - b, b);
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> n;

	while(n--)
	{
		cin >> a >> b;
		int g = gcd(a, b);

		cout << a * b / g << endl; 
	}
	
    return 0;
}