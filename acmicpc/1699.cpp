#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>
#include <climits>
using namespace std;

int N;
int DP[100001];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N;

	int sqrtN = (int)(sqrt(N));

	for(int i = 1; i <= 100000; i++)
	{
		DP[i] = INT_MAX;
	}

	for(int i = 1; i <= sqrtN; i++)
	{
		int square = i * i;
		if(square <= N)
			DP[square] = 1;
	}

	for(int i = 1; i <= sqrtN; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			int square = i * i;
			if(j + square <= N)
				DP[j + square] = min(DP[j + square], DP[j] + 1);
			else
				break;
		}
	}

	cout << DP[N] << endl;

    return 0;
}