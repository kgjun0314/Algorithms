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

int a, b;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	while(true)
	{
		cin >> a >> b;
		if(a == 0 && b == 0)
		{
			break;
		}

		if(b % a == 0)
		{
			cout << "factor" << endl;
		}
		else if(a % b == 0)
		{
			cout << "multiple" << endl;
		}
		else
		{
			cout << "neither" << endl;
		}
	}

    return 0;
}
