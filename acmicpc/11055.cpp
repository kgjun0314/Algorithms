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

long long N;
vector<long long> vec;
vector<long long> dp;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N;
    vec.resize(N + 1);
    dp.resize(N + 1);

    for(int i = 1; i <= N; i++)
    {
        cin >> vec[i];
    }

    for(int i = 1; i <= N; i++)
    {
        dp[i] = vec[i];
        for(int j = 1; j < i; j++)
        {
            if(vec[i] <= vec[j])
                continue;
            dp[i] = max(dp[i], dp[j] + vec[i]);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
}