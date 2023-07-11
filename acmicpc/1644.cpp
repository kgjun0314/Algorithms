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

bool isPrime(int N) 
{
	if(N < 2)
		return false;
	for(int i = 2; i * i <= N; i++) 
	{
		if(N % i == 0)
			return false;
	}
	return true;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N;

	v.push_back(0);

	for(int i = 2; i <= N; i++)
	{
		if (isPrime(i))
      		v.push_back(v.back() + i);
	}

	long long i = 0;
	long long j = 1;
	long long ans = 0;

	while(j < v.size())
	{
		if(v[j] - v[i] < N)
		{
			j++;
		}
		else if(v[j] - v[i] >= N)
		{
			if(v[j] - v[i] == N)
				ans++;
			i++;
		}
	}

	cout << ans << endl;

    return 0;
}