/*
ID: fy.q1
LANG: C++
TASK: subset
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int N , S;
int ans = 0;

int found[1000][40];

// Finds how many ways is it possible to contruct numbers of such sequence


/*
int solve(int x, int pos){

	if(x == 0){
		for(int i = 1 ; i <= N ; i++)
			if(used[i]) cout << i << " ";
		cout << endl;
		return 1;
	}
	int result = 0;

	for(int j = pos ; j < N ; j++){
		if(j > x) break;
		if(!used[j]){
			used[j] = true;
			result += solve(x-j,pos+1);
			used[j] = false;
		}
	}
	return result;
}

	if(x < 0 || k < 0) 
		return 0;
	if(x == 0 && k == 0){
		found[x][k] = 1;
		return 1;
	}
	if(found[x][k] != -1) return found[x][k];
	return (x,k-1) + (x-k,k-1);
*/



int solve(int x , int k) //making the value x using elements 1..k
{
	if(x < 0 || k < 0) return 0;
	if(found[x][k] != -1) return found[x][k];
	if(x == 0 && k == 0) return found[x][k] = 1;
	return found[x][k] = solve(x, k - 1) + solve(x - k, k - 1);
}


int main()
{
	ios_base::sync_with_stdio(false);
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    memset(found , -1 , sizeof(found));

    cin >> N;
    S = N * (N + 1);
    S = S / 2;
    if(S % 2 == 1){
    	cout << 0 << "\n";
    	return 0;
    }
    cout << solve((S/2)-N , N-1) << "\n";

    return 0;
}