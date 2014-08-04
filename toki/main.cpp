#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int N;
ll location[100010];
ll income[100010];

ll self[100010];
ll cross[100010];

ll ans = 0;
ll total_p = 0;

ll solve()
{

}

ll search()
{
	int lo = 0;
	int hi = 10000;
	while(lo != hi) {
		mid = (lo+hi+1)/2;
		if(solve(mid)) lo = mid;
		else hi = mid - 1;
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	scanf("%d" , &N);
	for(int i = 1 ;i <= N ; i++){
		scanf("%lld %lld" , location+i, income+i);
		self[i] = location[i] * income[i];
		total_p += income[i];
	}
	
	for(int i = 1 ; i <= N ; i++)
		cross[i] = location[i] * (total_p - income[i]);
	
	cout << total_p << "\n";
	/*
	for(int i = 1 ;i <= N ; i++)
		for(int j = i+1 ;j <= N ; j++) {
			ans += abs(location[j] - location[i]) * abs(income[j] - income[i]);
		}

	cout << ans << "\n";
	*/
	return 0;
}