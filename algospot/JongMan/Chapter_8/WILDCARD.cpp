#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int C, N;
int cache[101][101];
string W, S;

bool matchMemoized(int w, int s)
{
    int& ret = cache[w][s];
    if(ret != -1)
        return ret;
    while(s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s]))
    {
        ++w;
        ++s;
    }
    if(w == W.size())
        return ret = (s == S.size());
    if(W[w] == '*')
        for(int skip = 0; skip + s <= S.size(); ++skip)
            if(matchMemoized(w + 1, s + skip))
                return ret = 1;
    return ret = 0;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> C;
    while(C--)
    {
        cin >> W;
        vector<string> ret;
        cin >> N;
        while(N--)
        {
            cin >> S;
            memset(cache, -1, sizeof(cache));
            if(matchMemoized(0, 0)) 
                ret.push_back(S);
        }
        sort(ret.begin(), ret.end());
        for(int i = 0; i < ret.size(); i++)
            cout << ret[i] << endl;
    }
    return 0;
}