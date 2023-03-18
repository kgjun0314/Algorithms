#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

int N;
int sum = 0;
vector<int> v;

void solve(int start, int end)
{
    if(start == end)
    {
        return;
    }
    else if(end == start + 1)
    {
        sum += v[start] * v[end];
        return;
    }
    int mid = find(v.begin(), v.end(), (v[start] + v[end]) / 2) - v.begin();
    solve(start, mid);
    solve(mid + 1, end);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        v.push_back(i);
    }

    solve(0, N - 1);

    cout << sum << endl;

    return 0;
}