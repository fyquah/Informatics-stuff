#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T;


int main(){
	ios_base::sync_with_stdio(false);
	cin >> T;
	for(int trial = 0 ; trial < T ; trial++){
		int N ;
		char c;
		pair <int , int> all[1010];
		int cur = 0;
		int ans = 0;

		memset(all , 0 , sizeof(all));

		cin >> N >> c;
		for(int i = 0 ; i < N ; i++)
			cin >> all[i].first >> all[i].second;

		sort(all, all+N);

		priority_queue <int> q;

		if(c == 'A') N--;

		if(N % 2 == 0) ans = all[0].second;
		else ans = 0;

		for(int i = N % 2 ; i < N ; i++)
		{
			q.push(all[i].second);
			q.push(all[++i].second);
			ans += q.top();
			q.pop();
		}

		cout << ans << "\n";
	}
}