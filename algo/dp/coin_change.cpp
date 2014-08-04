#include <stdio.h>
#include <algorithm>
const int inf = 1 << 29;

int N = 25;
int coins[4] = {1,3,4,5}; // some really awkward currency!
int dp[10000];

int main()
{
	for(int i = 1 ; i <= N ; i++)
		dp[i] = inf;
	dp[0] = 0; // you need zero coins to form zero amount

	for(int i = 0 ; i < 4 ; i++){
		for(int j = 0 ; j <= N ; j++){

			if(j + coins[i] <= N)
				dp[j + coins[i]] = std::min(dp[j] + 1, dp[j + coins[i]]);
		}
	}

	for(int i = 0 ; i <= N ; i++)
		printf("%d ->  %d \n" , i , dp[i]);

	printf("You need a minimum of %d coins to make $%d\n" , dp[N] , N);

	return 0;
}