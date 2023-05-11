#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <queue>
#define endl "\n"
using namespace std;

int N, a, b, S = 0;
vector<int> A;
vector<int> B;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> a;
        A.push_back(a);
    }

    for(int i = 0; i < N; i++)
    {
        cin >> b;
        B.push_back(b);
    }

    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    for(int i = 0; i < N; i++)
    {
        S += A[i] * B[i];
    }

    cout << S << endl;

    return 0;
}