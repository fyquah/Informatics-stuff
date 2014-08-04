/*
ID: fy.q1
LANG: C++
TASK: nocows
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

const int MOD = 9901;

int main() {
    int dp[101][202], N, K;
    memset(dp , 0 , sizeof(dp));
    // dp [HEIGHT][NUMBER_OF_NODES]
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);
    scanf("%d %d", &N, &K);
 
    for(int i=1; i<=K; i++)
        dp[i][0] = dp[i][1] = 1;
 
    for(int h=1; h<=K; h++)
        for(int n=1; n<=N; n+=2)
            for(int c=1; c<n; c+=2)
                dp[h][n] = (dp[h][n] + dp[h-1][c]*dp[h-1][n-c-1])%9901;
 
    cout << (dp[K][N] - dp[K-1][N] + 9901)%9901 << endl;
    return 0;
}