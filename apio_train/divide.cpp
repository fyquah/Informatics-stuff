#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;

int N;
int x[100010];
int e[100010];
int g[100010];

ll energy[100010];
ll gold[100010];
ll ori[100010];

ll ans = 0;

int search(int start)
{
	int lo = start;
	int hi = N;
	int mid;
	while(lo != hi) {
		 mid = (lo + hi)/2 +1;
		if(energy[mid] - energy[start-1] >= x[mid] - x[start]) lo = mid;
		else hi = mid -1;
	}
	return lo;
}

int main()
{
	ios_base::sync_with_stdio(false);
	freopen("divide.in" , "r" , stdin);
	freopen("divide.out" , "w" , stdout);
	scanf("%d ",&N);
	for(int i = 1 ; i<= N ; i++)
		scanf("%d %d %d",x+i,g+i,e+i);
	for(int i = 1 ; i<= N ; i++){
		gold[i] = gold[i-1] + g[i];
		ori[i] = ori[i-1] + e[i];
		energy[i] = ori[i];
	}

	for(int i = N ; i > 1 ; i--){
		if(e[i] > x[i] - x[i-1]){
			int a = e[i] - (x[i] - x[i-1]);
			energy[i-1] += a;
			e[i-1] += a;
			e[i] -= a;
		}
	}

	for(int i = 1 ; i <= N ; i++){
		ans = max(ans ,gold[search(i)] - gold[i-1]);
		energy[i] = ori[i];
	}
	printf("%lld\n" , ans);

	return 0;
}