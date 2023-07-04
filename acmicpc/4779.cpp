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

int N;

void cantor(int n)
{
    if(n == 0)
    {
        cout << "-";
        return;
    }

    cantor(n - 1);

    for(int i = 0; i < pow(3, n - 1); i++)
    {
        cout << " ";
    }

    cantor(n - 1);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> N)
    {
        cantor(N);
        cout << endl;
    }

    return 0;
}