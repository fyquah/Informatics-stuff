#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

pair <long , long> all[13];
int n;

int on_the_right[13]; //if on the right is 0 , means that no cycle
int partner[13];

int counter;

bool execute() //returns true if cycle exists
{
	//let bessie start at one of the holes
	
	for(int i = 1 ; i <= n; i++) {
		int pos = i;
		for(int count = 0 ; count < n ; count++){
			pos = on_the_right[partner[pos]];
		}
		if(pos != 0) return true;
	}	
	return false;
}

void solve(){
	int i;
	for(i = 1 ; i <= n ; i++)
		if(partner[i] == 0) break;
	
	if(i == n + 1){
		if(execute()) counter++;
		return;
	}

	for(int j = i + 1 ; j<= n ; j++)
		if(partner[j] == 0) {
			partner[i] = j;
			partner[j] = i;
			solve();
			partner[i] = 0;
			partner[j] = 0;
		}
}

int main()
{
	ifstream fin("wormhole.in");
	fin >> n;
	for(int i =1 ; i <= n ;i++){
		fin >> all[i].first;
		fin >> all[i].second;
	}
	fin.close();

	for(int i = 1 ; i <= n ;i++){
		int final = 0;
		for(int j = 1 ; j <= n ; j++) {	
			if(j == i) continue;
			if(all[i].second == all[j].second 
				&& all[i].first < all[j].first 
				&& (final == 0 || all[j].first - all[i].first < all[final].first - all[i].first) )
				final = j;
		}
		on_the_right[i] = final;
	}

	solve();

	ofstream fout("wormhole.out");
	fout << counter << "\n";
	fout.close();
	return 0;
}