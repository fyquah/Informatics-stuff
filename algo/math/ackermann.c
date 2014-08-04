#include <stdio.h>
#include <string.h>

long long dp[100][100];

long long A(int m , int n)
{
	if(dp[m][n] != -1)
		return dp[m][n];
	else if(m == 0)
		return n + 1;
	else if(m > 0 && n == 0)
		return A(m-1 , 1);
	else
		return A(m-1 , A(m,n-1));
}

int main()
{
	memset(dp , -1 , sizeof(dp));
	int x = 1;
	while(x) {
		int m , n;
		scanf("%d %d" , &m, &n);
		printf("%lld\n" , A(m,n));
	}
		return 0;
}