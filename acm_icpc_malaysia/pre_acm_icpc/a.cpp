#include <iostream>

using namespace std;

int dp[100];

int factorial(int a){
  if(a == 1 || a == 0)
    return 1;
  else if(dp[a])
    return dp[a];
  else
    return dp[a] = a * factorial(a-1);
}

int main()
{
  int N;
  cin >> N;

  for(int i = 0; i < N ; i++){
    int val;
    cin >> val;
    cout << factorial(val) << "\n";
  }

  return 0;
}
