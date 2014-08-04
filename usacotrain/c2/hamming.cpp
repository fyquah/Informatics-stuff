/*
ID: fy.q1
LANG: C++
TASK: hamming
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <bitset>
using namespace std;

int N , B , D;
int matrix[300][300];
vector <int> ans;

int main()
{
	clock_t tstart = clock();
	ios_base::sync_with_stdio(false);
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
	cin >> N >> B >> D;

	//span the adjacency matrix first
	for(int i = 0 ; i < (1 << B) ; i++){
		for(int j = i + 1 ; j < (1<<B) ; j++){
			int n = 0;
			int a = i^j;
			for(int k = 1 ; k < (1<<B) ; k *= 2)
				if((a&k) == k) n++;
			if(n >= D) matrix[i][j] = matrix[j][i] = 1;

		}
	}

	ans.push_back(0);
	for(int i =0 ; i < (1<<B) ; i++){
		for(int j =0 ; j < ans.size() ; j++){
			if(!matrix[i][ans[j]])goto rejected;
		}
		ans.push_back(i);
		rejected:if(ans.size() == N) break;
	}

	cout << ans[0];
	for(int i =1 ; i < N ; i++){
		if(i % 10 == 0) cout << "\n";
		else cout << " ";
		cout << ans[i];
	}
	cout << "\n";
	return 0;
}