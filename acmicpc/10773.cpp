#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <stack>
using namespace std;

int K, item;
long long sum = 0;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	stack<int> st;

	cin >> K;
	while(K--)
	{
		cin >> item;
		if(item == 0)
		{
			sum = sum - st.top();
			st.pop();
		}
		else
		{
			sum = sum + item;
			st.push(item);
		}
	}

	cout << sum << endl;

    return 0;
}