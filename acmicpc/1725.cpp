#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

long long C, N, H;

long long solve(vector<long long>& h, long long left, long long right)
{
    if(left == right)
        return h[left];
    
    long long mid = (left + right) / 2;
    
    long long ret = max(solve(h, left, mid), solve(h, mid + 1, right));
    
    long long lo = mid, hi = mid + 1;
    long long height = min(h[lo], h[hi]);
    
    ret = max(ret, height * 2);
    
    while(left < lo || hi < right)
    {
        if(hi < right && (lo == left || h[lo - 1] < h[hi + 1]))
        {
            ++hi;
            height = min(height, h[hi]);
        }
        
        else
        {
            --lo;
            height = min(height, h[lo]);
        }
        
        ret = max(ret, height * (hi - lo + 1));
    }
    
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    
    vector<long long> h;
    
    while(N--)
    {
        cin >> H;
        h.push_back(H);
    }
    
    cout << solve(h, 0, h.size() - 1) << endl;
    return 0;
}