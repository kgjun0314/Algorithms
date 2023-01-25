#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <stack>
using namespace std;

int C;
string str;

bool wellMatched(const string& formula)
{
	stack<char> openStack;

	for(int i = 0; i < formula.size(); i++)
	{
		if(formula[i] == '(')
		{
			openStack.push(formula[i]);
		}
		else
		{
			if(openStack.empty())
			{
				return false;
			}
			openStack.pop();
		}
	}
	
	return openStack.empty();
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> C;
	while(C--)
	{
		cin >> str;
		if(wellMatched(str))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	
    return 0;
}