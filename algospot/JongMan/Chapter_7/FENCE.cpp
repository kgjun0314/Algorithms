#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int C, N, H;

int solve(vector<int>& h, int left, int right)
{
    if(left == right)
        return h[left];
    
    int mid = (left + right) / 2;
    
    int ret = max(solve(h, left, mid), solve(h, mid + 1, right));
    
    int lo = mid, hi = mid + 1;
    int height = min(h[lo], h[hi]);
    
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
    
    cin >> C;
    
    while(C--)
    {
        cin >> N;
        vector<int> h;
        while(N--)
        {
            cin >> H;
            h.push_back(H);
        }
        cout << solve(h, 0, h.size() - 1) << endl;
    }
    
    return 0;
}