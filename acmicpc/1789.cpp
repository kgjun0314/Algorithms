#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>
#include <climits>
using namespace std;

long long S;
long long N = 1;
long long cnt = 0;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> S;

	while(S >= N)
	{
		S = S - N;
		cnt++;
		N++;
	}
	
	cout << cnt << endl;

    return 0;
}