#include <cstdio>
#include <cstring>

int main()
{
  int MAX_N = 7489;
  int coins[5] = {1,5,10,25,50};
  int dp[10000];
  memset(dp , 0 , sizeof(dp));
  dp[0] = 1;

  for(int j = 0 ; j < 5 ; j++)
    for(int i = 0 ; i <= MAX_N ; i++){
      if(i + coins[j] > MAX_N)
        break;
      else
        dp[i + coins[j]] += dp[i];
    }

  // for(int i = 0 ; i < 10 ; i++)
  //   printf("%d " , dp[i]);
    int N;
    scanf("%d" , &N);
    for(int i = 0 ; i < N ; i++){
      int val;
      scanf("%d" , &val);
      printf("%d\n" , dp[val]);
    }

  return 0;
}
