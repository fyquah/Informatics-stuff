#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string all[30];
int w[30];
int N;
int ans =0;

void solve(int pos , int temp){
	if(pos == N){
		if(temp == 1 << 26 -1) ans++;
		return;
	}

	solve(pos + 1 , temp);
	solve(pos + 1 , temp | w[pos]);
}


int main()
{
	cin >> N;
	for(int i =0 ;i < N; i++){
		cin >> all[i];	
		for(int j = 0 ;  j < all[i].length() ; j++){
			w[i] = w[i] | 1 << all[i][j] - 'a';
		}
	}



	rek(0,0);

	cout << ans << "\n";
}