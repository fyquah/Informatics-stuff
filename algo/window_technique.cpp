#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX_N 50000
#define MAX_ID 1000000

using namespace std;

FILE * fin;
FILE * fout;

int N, K;
int all[MAX_N + 1];
int breed[MAX_ID + 1];
int ans = -1;

/*
vector < vector <int> > id_collection (MAX_ID + 1);
bool map_of_all[MAX_ID + 1]; //for program speed purposes
vector <int> list_of_all; //vector containing a list of all id of participating cows


bool test_crowded(int a, int b)
{
	if(abs(a-b) <= K) return true;
	else return false;
}

bool test_function(int a, int b)
{
	return (a > b);
}
*/


int main()
{
	fin = fopen("proximity.in" , "r");
	fout = fopen("proximity.out" , "w");
	fscanf(fin , "%d %d" , &N , &K);

	for(int i = 0 ;i < N ; i++){
		fscanf(fin , "%d" , all + i);
	}

	for(int i = 0 ; i < N ; i++){
		breed[all[i]]++;
		if(i > K) breed[all[i-K-1]]--;
		if(breed[all[i]] > 1) ans = max(ans , all[i]);
	}

	fprintf(fout, "%d\n", ans);

	return 0;
	/*
	fin = fopen("proximity.in" , "r");
	fout = fopen("proximity.out" , "w");
	fscanf(fin , "%d %d" , &N , &K);

	for(int i = 0 ;i < N ; i++){

		fscanf(fin , "%d" , all + i);

		id_collection[all[i]].push_back(i);

		if(map_of_all[all[i]]) continue;
		else{
			map_of_all[all[i]] = true;
			list_of_all.push_back(all[i]);
		}
	}

	
	sort(list_of_all.begin() , list_of_all.end() , test_function);

	for(int i = 0 ; i < list_of_all.size() ; i++){
		int x = list_of_all[i];
		if(id_collection[x].size() <= 1) continue;
		for(int j = 1 ; j < id_collection[x].size() ; j++){
			if(test_crowded(id_collection[x][i] ,id_collection[x][i-1])){
				fprintf(fout , "%d\n" , x);
				return 0;
			}
		}
	}

	int a = -1;
	fprintf(fout , "%d\n" , a);
	return 0;
	*/

}