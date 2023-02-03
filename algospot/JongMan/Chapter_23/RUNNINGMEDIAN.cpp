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
#define endl "\n"
using namespace std;

int C, N, A, B;

struct RNG {
	int seed, a, b;
	RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}
	int next() {
		int ret = seed;
		seed = ((seed * (long long)a) + b) % 20090711;
		return ret;
	}
};

int runningMedian(int n, RNG rng)
{
	priority_queue<int, vector<int>, less<int> > maxHeap;
	priority_queue<int, vector<int>, greater<int> > minHeap;
	int ret = 0;

	for(int cnt = 1; cnt <= n; cnt++)
	{
		if(maxHeap.size() == minHeap.size())
		{
			maxHeap.push(rng.next());
		}
		else
		{
			minHeap.push(rng.next());
		}
		if(!minHeap.empty() && !maxHeap.empty() && maxHeap.top() > minHeap.top())
		{
			int a = maxHeap.top();
			int b = minHeap.top();
			maxHeap.pop();
			minHeap.pop();
			maxHeap.push(b);
			minHeap.push(a);
		}
		ret = (ret + maxHeap.top()) % 20090711;
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
		cin >> N >> A >> B;
		cout <<	runningMedian(N, RNG(A, B)) << endl;
	}

    return 0;
}