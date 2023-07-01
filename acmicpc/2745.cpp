#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <sstream>
#include <cstdlib>
#include <set>
#include <cmath>
#define endl "\n"
using namespace std;

string str;
int B;
long long result = 0;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str >> B;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] >= 65)
        {
            result += (str[i] - 55) * pow(B, (str.length() - i - 1));
        }
        else if(str[i] >= 48)
        {
            result += (str[i] - 48) * pow(B, (str.length() - i - 1));
        }
    }

    cout << result << endl;

    return 0;
}