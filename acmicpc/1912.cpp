#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

long long n, sum = 0;
vector<long long> dp(100001, -1001);

int main(void) 
{    
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n;
    vector<long long> v(n);
    for(long long i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for(long long i = 0; i < n; i++)
    {
        if(i == 0)
        {
            dp[i] = v[i];
        }
        else
        {
            dp[i] = max(v[i], dp[i - 1] + v[i]);
        }
    }
    
    int maxval = *max_element(dp.begin(), dp.end());
    cout << maxval << endl;

    return 0;
}