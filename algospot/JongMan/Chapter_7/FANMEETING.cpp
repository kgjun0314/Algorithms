#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/*
void normalize(vector<int>& num)
{
    num.push_back(0);
    for(int i = 0; i+1 < num.size(); i++)
    {
        if(num[i] < 0)
        {
            int borrow = (abs(num[i]) + 9) / 10;
            num[i + 1] -= borrow;
            num[i] += borrow * 10;
        }
        else
        {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    while(num.size() > 1 && num.back() == 0) num.pop_back();
}
*/

vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
	vector<int> c(a.size() + b.size() + 1, 0);
	for(int i = 0; i < a.size(); i++)
		for(int j = 0; j < b.size(); j++)
			c[i + j] += a[i] * b[j];
	return c;
}

void addTo(vector<int>& a, const vector<int>& b, int k) 
{
	if(a.size() < b.size() + k)
		a.resize(b.size() + k);
	for(int i = 0; i < b.size(); i++)
        a[i + k] += b[i];
    //normalize(a);
}

void subFrom(vector<int>& a, const vector<int>& b)
{
	for(int i = 0; i < b.size(); i++) 
        a[i] -= b[i];
    //normalize(a);
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) 
{
	int an = a.size(), bn = b.size();
	if(an < bn) return karatsuba(b, a);
	if(an == 0 || bn == 0) return vector<int>();
	if(an <= 50) return multiply(a, b);

	int half = an / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
	// z2 = a1 * b1
	vector<int> z2 = karatsuba(a1, b1);
	// z0 = a0 * b0
	vector<int> z0 = karatsuba(a0, b0);
	// a0 = a0 + a1; b0 = b0 + b1
	addTo(a0, a1, 0); addTo(b0, b1, 0);
	// z1 = (a0 * b0) - z0 - z2;
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);
	// ret = z0 + z1 * 10^half + z2 * 10^(half*2)
	vector<int> ret;
	addTo(ret, z0, 0); 
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;
}

int hugs(const string& members, const string& fans) 
{
	int N = members.size(), M = fans.size();
	vector<int> A(N), B(M);
	for(int i = 0; i < N; i++) A[i] = (members[i] == 'M');
	for(int i = 0; i < M; i++) B[M - i - 1] = (fans[i] == 'M');
	vector<int> C = karatsuba(A, B);
	int allHugs = 0;
	for(int i = N - 1; i < M; ++i) 
		if(C[i] == 0)
			allHugs++;
	return allHugs;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int C;
    
    cin >> C;
    
    while(C--)
    {
        char members[200001], fans[200001];
        cin >> members >> fans;
        cout << hugs(members, fans) << endl;
    }
    
    return 0;
}