#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#define MAX_N 15
#define MAX_K 50

using namespace std;

int N , K;
int all[MAX_N + 1];
char map[MAX_N + 1][MAX_N + 1];

int profile[MAX_N + 1];

int ans = 0;

void solve(int element){
	if(element > N) {
		ans++;
		return;
	}

	for(int i = 1 ; i <= 3 ; i++){
		for(int j = 1 ; j < element ; j++){
			if( (map[element][j] == 'S' && profile[j] != i) || (map[element][j] == 'D' && profile[j] == i) )
				goto next; //contradiction
			profile[element] = i;
			solve(element + 1);
			next: profile[element] = 0;
		}
		
		
	}
}

int main()
{
	ifstream fin("assign.in");
	fin >> N >> K;
	for(int i = 0 ; i < K ; i++){
		char c;
		int a,b;
		fin >> c >> a >> b;
		map[a][b] = c;
		map[b][a] = c;
	}

	solve(1);

	ofstream fout("assign.out");
	fout << ans << "\n";
	fout.close();
	return 0;
}