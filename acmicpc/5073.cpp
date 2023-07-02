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

    while(A != 0 && B != 0 && C != 0)
    {
        if(A + B <= C || A + C <= B || B + C <= A)
        {
            cout << "Invalid" << endl;
        }
        else if(A == B && B == C && C == A)
        {
            cout << "Equilateral" << endl;
        }
        else if(A == B || B == C || C == A)
        {
            cout << "Isosceles" << endl;
        }
        else if(A != B && B != C && C != A)
        {
            cout << "Scalene" << endl;
        }
        cin >> A >> B >> C;
    }
    
    return 0;
}