#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> v;
vector<long long> setA, setB;
long long N, C;

void combine(int left, int right, vector<long long>& set, long long sum)
{
    if(left > right)
    {
        set.push_back(sum);
        return;
    }

    combine(left + 1, right, set, sum); // v[left]를 선택안한거
    combine(left + 1, right, set, sum + v[left]); // v[left]를 선택한거
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;

    v.resize(N);
    for(int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    combine(0, N / 2, setA, 0);
    combine(N / 2 + 1, N - 1, setB, 0);
    
    sort(setB.begin(), setB.end());

    long long ans = 0;
    for(int i = 0; i < setA.size(); i++)
    {
        ans += upper_bound(setB.begin(), setB.end(), C - setA[i]) - setB.begin();
    }

    cout << ans << endl;

    return 0;
}