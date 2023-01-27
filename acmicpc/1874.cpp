#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
using namespace std;

int n;
int cur = 1;
int num;
bool flag = true;
stack<int> st;
vector<char> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> num;
		while(cur <= num)
		{
			st.push(cur);
			cur++;
			ans.push_back('+');
		}
		if(st.top() == num)
		{
			st.pop();
			ans.push_back('-');
		}
		else
		{
			cout << "NO" << '\n';
			flag = false;
			break;
		}
	}

	if(flag)
	{
		for(int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << '\n';
		}
	}
	return 0;
}