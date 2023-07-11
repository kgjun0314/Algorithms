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

long long N, S, elem;
vector<long long> v;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	long long i = 0;
	long long j = 1;
	long long ans = 100002;

	cin >> N >> S;

	v.push_back(0);

	for(int i = 1; i <= N; i++)
	{
		cin >> elem;
		v.push_back(v[i - 1] + elem);
	}

	while(j <= N)
	{
		if(v[j] - v[i] < S)
		{
			j++;
		}
		else if(v[j] - v[i] >= S)
		{
			if(j - i <= ans)
				ans = j - i;
			i++;
		}
	}

	if(ans == 100002)
		cout << 0 << endl;
	else 
		cout << ans << endl;

    return 0;
}