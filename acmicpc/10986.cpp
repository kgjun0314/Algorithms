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

long long N, M, num;
vector<long long> v;
vector<long long> cnt(1001, 0);

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N >> M;

	v.push_back(0);

	for(int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back((v[i] + num) % M);
		cnt[v[i + 1]]++;
	}

	long long ans = cnt[0];

	for(int i = 0; i < M; i++)
	{
		ans += cnt[i] * (cnt[i] - 1) / 2; 
	}

	cout << ans << endl;

    return 0;
}