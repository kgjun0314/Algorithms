#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int T;

void recursion(string s, int l, int r, int cnt)
{
    cnt++;
    if(l >= r)
        cout << "1 " << cnt << endl;
    else if(s[l] != s[r])
        cout << "0 " << cnt << endl;
    else 
        recursion(s, l+1, r-1, cnt);
}

void isPalindrome(string s)
{
    recursion(s, 0, s.length()-1, 0);
}

int main(void)
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    
    cin >> T;

    while(T--)
    {
        string str;
        cin >> str;
        isPalindrome(str);
    }

    return 0;
}