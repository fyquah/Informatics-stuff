#include <cstdio>
#include <cstring>
#include <algorithm>

int main()
{
  int T;
  scanf("%d" , &T);
  for( ; T > 0 ; T--){
    int N;
    scanf("%d" , &N);
    int most = 0;
    int most_count = 0;
    int counter[10010];
    memset(counter , 0 ,sizeof(counter));
    for(int i = 0 ; i < N ; i++){
      int a;
      scanf("%d" , &a);
      counter[a]++;
      if(counter[a] >= most_count){
        most = counter[a] == most_count ? std::min(a , most) : a;
        most_count = counter[a];
      }
    }
    printf("%d %d\n" , most , most_count);
  }
  return 0;
}
