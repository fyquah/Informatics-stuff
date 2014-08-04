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
		int ans = 0;
		for(int i =0 ; i < N ; i++){
			int val;
			cin >> val;
			ans += val;
		}
		
		cout << ans << "\n";
	}    
    return 0;
}
