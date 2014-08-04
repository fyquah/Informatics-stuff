#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int inf = 1 << 30;

int main()
{
	int T;
	cin >> T;
	for(int trial = 0; trial < T ; trial++){
		int N;
		cin >> N;
		int all[5010];
		for(int i =0 ; i < N ; i++)
			cin >> all[i];
		sort(all , all + N);
		int ans = inf;
		for(int i = 1 ; i < N ; i++)
			ans = min(ans , all[i] - all[i-1]);
		cout << ans << "\n";
	}    
    return 0;
}
