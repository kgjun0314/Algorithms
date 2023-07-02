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

int A, B, C;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B >> C;

    if(A + B <= C)
    {
        while(A + B <= C)
        {
            C--;
        }
        cout << A + B + C << endl;
    }
    else if(A + C <= B)
    {
        while(A + C <= B)
        {
            B--;
        }
        cout << A + B + C << endl;
    }
    else if(B + C <= A)
    {
        while(B + C <= A)
        {
            A--;
        }
        cout << A + B + C << endl;
    }
    else
    {
        cout << A + B + C << endl;
    }
    
    return 0;
}