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
#include <set>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
int ans = 0;
int M , N;
int all[100010];
int number[100010]; //indicates number of total direct subordinates an employee has
int sub[100010];
vector < set<int> > mat(100010);


bool solve(int k) { // k is the maximum number of subordinates a 
	//we now have N employees, including the boss of course
	int count[N+10];

	for(int i = 1 ; i <= N ; i++)
		count[i] = number[i];

	for(int i = N ; i >= 1 ; i--) {
		if(sub[i] <= k) continue;

		priority_queue< int  , vector<int> , std::greater<int> > child;

		for(set<int>::iterator it = mat[i].begin() ; it != mat[i].end() ; it++)
			child.push(count[*it]+1);

		int total = 0;
		int len = child.size();
		for(int j = 0 ; j < len-k ; j++){
			total+= child.top();
			child.pop();
		}

		int pos = i;
		while(pos >= 1){
			count[pos] -= total;
			pos = all[pos];
		}

	}

	if(count[1]+1 >= M) return true;
	else return false;
}

//binary search for the value of K
//if a large value is  valid, definitely smaller value is also valid
int search()
{
	int lo = 0;
	int hi = N;
	int mid;
	while(lo != hi) {
		mid = (lo+hi)/2;
		if(solve(mid)) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> N >> M;


	if(M == N) { // we want to retain all the employees, aka don't sack anyone
		for(int i = 1 ; i<= N ; i++){
			cin >> all[i];
			number[all[i]]++;
			sub[all[i]]++;
		}
		for(int i = 1;  i<= N ; i++){
			ans = max(ans , sub[i]);
		}
		cout << ans << "\n";
		return 0;
	}

	for(int i = 2 ; i <= N ; i++){
		cin >> all[i];
		number[all[i]]++;
		sub[all[i]]++;
		mat[all[i]].insert(i);
		int pos = all[i];
		while(pos > 1) {
			number[all[pos]]++;
			pos = all[pos];
		}
	}

	cout << search() << "\n";
	return 0;
}