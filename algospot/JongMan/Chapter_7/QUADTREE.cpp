#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int C;
string str;

string reverse(string::iterator& it)
{
    char head = *it;
    ++it;
    if(head == 'b' || head == 'w')
        return string(1, head);
    
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);
    
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> C;
    
    while(C--)
    {
        cin >> str;
        string::iterator it = str.begin();
        cout << reverse(it) << endl;
    }
    
    return 0;
}