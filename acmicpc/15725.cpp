#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int idx = -1;
    
    string s;
    cin >> s;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'x')
        {
            idx = i;
        }
    }
    
    if(idx == -1)
    {
        cout << 0;
    }
    
    else if(idx == 0 || (idx == 1 && s[0] == '-'))
    {
        if(idx == 0)
            cout << 1 << endl;
        else
            cout << -1 << endl;
    }
    
    /*else
    {
        s[idx] = 0;
		printf("%s\n",s.c_str());
    }*/
    
    else
    {
        char diff[idx+1];
        strncpy(diff, s.c_str(), idx);
        cout << diff;
    }
    
    return 0;
}