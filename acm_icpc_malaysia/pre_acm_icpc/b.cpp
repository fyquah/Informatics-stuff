#include <cstdio>

using namespace std;

int main(){
  int T;
  scanf("%d" , &T);
  for( ; T > 0 ; T--){
    int N , C;
    scanf("%d %d" , &N  , &C);
    int required = 0;
    for(int i = 0 ; i < N ; i++) {
      int temp;
      scanf("%d" , &temp);
      required += temp;
    }
    if(C >= required) printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}
