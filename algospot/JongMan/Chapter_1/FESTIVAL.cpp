#include <iostream>
using namespace std;

double Min;
int cost[1100];
int C, N, L;

void GetMinimumCost()
{
	int Sum = 0;
	double Average;
	Min = 98765432;
	
	for(int i = 1; i <= N - L + 1; i++) // i:1번 인덱스 부터, i:N-L+1번 인덱스를 시점으로 설정
	{
		for(int j = i + L - 1; j <= N; j++) // j:i+L-1번 인덱스 부터, j:N번 인덱스를 종점으로 설정
		{
			Sum = 0;
			for(int k = i; k <= j; k++) // i부터 j까지 모두 더한다.
			{
				Sum += cost[k];
			}
			
			Average = (double)Sum / (j - i + 1);
			
			if(Average < Min)
				Min = Average;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> C;
	for(int i = 0; i < C; i++)
	{
		cin >> N >> L;
		for(int j = 1; j <= N; j++)
		{
			cin >> cost[j];
		}
		GetMinimumCost();
		
		// printf("%.11lf\n", Min);
		cout.precision(11);
		cout << Min << endl;
	}
	return 0;
}
