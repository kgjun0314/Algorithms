#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

long long solve(long long A, long long B, long long C)
{
    if(B == 1)
        return A % C;
    
    if(B % 2 == 0)
        return (solve(A, B / 2, C) % C) * (solve(A, B / 2, C) % C) % C;
    else
        return ((solve(A, B / 2, C) % C) * (solve(A, B / 2, C) % C) % C) * A % C;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    long long A, B, C;
    
    cin >> A >> B >> C;
    
    cout << solve(A, B, C) << endl;
    
    return 0;
}