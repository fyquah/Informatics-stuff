//USACO January 2014
//This is a good example of recursion to do combinatric / permutation
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

//input data
FILE * fin;
FILE * fout;
int all[12];

//processing
int profile[12];
int filled[4] = {0,0,0,0};
//output purposes
int ans = -1;
int counter = 0;

void evaluate()
{
	int team[4] = {0,0,0,0};
	for(int i = 0; i < 12 ; i++)
	{
		if(profile[i] == 0) team[0] += all[i];
		else if(profile[i] == 1) team[1] += all[i];
		else if(profile[i] == 2) team[2] += all[i];
		else if(profile[i] == 3) team[3] += all[i];
	}
	int high = max(max(team[0] , team[1]) , max(team[2] , team[3]));
	int low = min(min(team[0] , team[1]) , min(team[2] , team[3]));
	if(high - low < ans || ans == -1) ans = high - low;
}

void solve(int player)
{
	if(player == 12){
		counter++;
		return;
	}

	for(int i = 0 ; i < 4 ; i++){
		if(filled[i] == 3) continue;
		filled[i]++;
		profile[player] = i;		
		solve(player + 1);
		filled[i]--;
	}
	return;

}

int main()
{
	fin = fopen("bteams.in" , "r");
	fout = fopen("bteams.out" , "w");
	for(int i = 0 ;i < 12 ;i++)
		fscanf(fin, "%d" , all + i);

	profile[0] = 0; //player 0 always in team 0 , Number of operations divided by four , 
					//remove this if you wanna permutate in terms of team
	filled[0] = 1; 

	solve(1);
	cout << counter << endl;
	fprintf(fout , "%d\n" , ans);
	return 0;
}