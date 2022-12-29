#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

long long N, T;
long long dp_f[200];
long long dp_g[200];
long long solve_f(long long);
long long solve_g(long long);

long long solve_f(long long N)
{
    if(N == 1 || N == 2 || N == 3)
    {
        return dp_f[N];
    }
    if(dp_f[N] != -1)
    {
        return dp_f[N];
    }
    return dp_f[N] = solve_g(N - 1) + solve_g(N - 3);
}

long long solve_g(long long N)
{
    if(N == 1 || N == 2)
    {
        return dp_g[N];
    }
    if(dp_g[N] != -1)
    {
        return dp_g[N];
    }
    return dp_g[N] = solve_f(N) + solve_f(N - 2);
}

int main(void) 
{    
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    memset(dp_f, -1, sizeof(dp_f));
    memset(dp_g, -1, sizeof(dp_g));

    dp_f[1] = 1;
    dp_g[1] = 1;
    dp_f[2] = 1;
    dp_g[2] = 2;
    dp_f[3] = 2;

    cin >> T;
    while(T--)
    {
        cin >> N;
        if(N % 2 == 0)
            cout << solve_g(N / 2) << endl;
        else
            cout << solve_f(N / 2 + 1) << endl;

    }
    
    return 0;
}