#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <stack>
using namespace std;

int C, K, N;

struct RNG {
	unsigned seed;
	RNG() : seed(1983) {}
	unsigned next() {
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}
};

int countRanges(int k, int n)
{
	RNG rng;
	queue<int> range;
	int ret = 0, rangeSum = 0;

	for(int i = 0; i < n; i++)
	{
		int newSignal = rng.next();
		rangeSum += newSignal;
		range.push(newSignal);

		while(rangeSum > k)
		{
			rangeSum -= range.front();
			range.pop();
		}

		if(rangeSum == k)
		{
			ret++;
		}
	}
	return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> C;
	while(C--)
	{
		cin >> K >> N;
		cout << countRanges(K, N) << endl;
	}
	
    return 0;
}