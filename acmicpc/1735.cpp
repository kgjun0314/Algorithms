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

int A, B, A2, B2, A3, B3;

int gcd(int a, int b)
{
    if(b)
        return gcd(b, a % b); 
    return a;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B >> A2 >> B2;

    A3 = B * B2;
    B3 = B * A2 + B2 * A;

    int gcdval = gcd(A3, B3);

    cout << B3 / gcdval << " " << A3 / gcdval << endl;
    
    return 0;
}