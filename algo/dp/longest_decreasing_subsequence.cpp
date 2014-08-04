#include <stdio.h>
#include <string.h>
#include <algorithm>

int arr[8] = {-7, 10, 9, 2, 3, 8, 8, 1};
int N = 8;
int dp[8]; // remembers the LIS ending at particular position

int main()
{
	int best = 1;

	for(int i = 0 ; i <N ; i++)
		dp[i] = 1;

	for(int i = 1 ; i < N ; i++){
		for(int j = 0 ; j < i ; j++){
			if(arr[j] > arr[i] && dp[j] >= dp[i]){
				dp[i] = dp[j] + 1;
				best = std::max(dp[i] , best);
			}
		}
	}

	printf("LDS is (also) %d\n" , best);
	return 0;
}