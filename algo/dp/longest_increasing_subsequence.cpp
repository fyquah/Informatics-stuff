// Note -> LIS = Longes increasing subsequence
#include <stdio.h>
#include <string.h>
#include <algorithm>

int arr[8] = {-7, 10, 9, 2, 3, 8, 8, 1};
int N = 8;
int dp[8]; // remembers the LIS ending at particular position

int main()
{
	// Initialize all the LIS to be 1
	int best = 1;

	for(int i = 0 ; i < N ; i++)
		dp[i] = 1;

	for(int i = 1 ; i < N ; i++){
		for(int j = 0 ; j < i ; j++){
			if(arr[j] < arr[i] && dp[j] >= dp[i]){
				dp[i] = dp[j] + 1;
				best = std::max(dp[i] , best);
			}
		}
	}

	printf("The LIS is %d\n" , best);
	return 0;
}

/*
int main()
{
	for(int i = 0 ; i < 8 ; i++)
		dp[i] = 1;

	int best = 1;

	for(int i = 1 ; i < N ; i++){
		for(int j = 0 ; j < i ; j++){
			if(arr[j] < arr[i] && dp[j] >= dp[i]){
				dp[i] = dp[j] + 1;
				best = std::max(best , dp[i]);
			}
		}
	}

	printf("The longest increasing subsequence is %d\n" , best);
	for(int i =0 ; i < N ; i++)
		printf("%d " , *(dp + i));
	return 0;
}
*/