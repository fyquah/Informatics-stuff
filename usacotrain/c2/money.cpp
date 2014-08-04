/*
ID: fy.q1
LANG: C++
TASK: money
*/
# include <iostream>
# include <fstream>
# include <algorithm>
# include <utility>
# include <vector>
# include <string>
# include <stdio.h>
# include <string>
# include <stdlib.h>
# include <sstream>
# include <math.h>
# include <cstring>
using namespace std;
typedef long long ll;

int main()
{
	int v , n;
	int coins[25];
	int dp[10001];
	cin >> v >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> coins[i];

	memset(dp , 0 , sizeof(dp));
	dp[0] = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	freopen("money.in" , "r" , stdin);
	freopen("money.out" , "w" , stdout);
	int v , n;
	ll dp[10001];
	ll coins[26];

	cin >> v >> n;
	for(int i = 0 ; i < v ; i++)
		cin >> coins[i];
	
	memset(dp , 0 , sizeof(dp));
	dp[0] = 1;

	for(int i = 0 ; i < v ; i++)
		for(int j = 0 ; j < n ; j++)
			if(dp[j] > 0 && j+coins[i] <= n)
				dp[j+coins[i]] += dp[j];

	cout << dp[n] << "\n";


	return 0;
}