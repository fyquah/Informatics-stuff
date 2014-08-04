/*
ID: fy.q1
LANG: C++
TASK: sort3
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#include <stack>
using namespace std;

int N;
int n[4];
int all[1010];
int ans = 0;
int x ,y;

int main(void)
{
	ios_base::sync_with_stdio(false);
	freopen("sort3.in" , "r", stdin);
	freopen("sort3.out" , "w", stdout);

	cin >> N;
	for(int i =0  ;i < N ; i++){
		cin >> all[i];
		n[all[i]]++;
	}

	for(int i = 0; i < N ;i++){
		if(i < n[1]){
			if(all[i] != 1){
				for(int j = (all[i]==2) ? n[1] : n[1] + n[2] ; j < N ; j++){
					if(all[j] == 1){
						swap(all[i] , all[j]);
						ans++;
						goto finish;
					}
				}
				for(int j = n[1] ; j < N ; j++){
					if(all[j] == 1){
						swap(all[i] , all[j]);
						ans++;
						break;
					}
				}
			}
			finish:;
		}
		else{
			if(all[i] != 2){
				for(int j = N - 1; j > i ; j--){
					if(all[j] == 2) {
						swap(all[i] , all[j]);
						ans++;
						break;
					}
				}
			}
		}

		if(i > n[1] + n[2]) break;
	}

	/*
	for(int i = 0 ; i < N ; i++)
		cout << all[i] << " ";
	*/
	cout << ans << "\n";
}