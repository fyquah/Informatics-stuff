/*
ID : fy.q1
LANG : C++
TASK : holstein
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

int V , G;
int vitamin[30];
int scoop[20][30];
bool profile[20];	//array containing the which scoop is being used

int ans = 1 << 30;
string sequence = "";

string convert_string(int x)
{
	stringstream ss;
	ss << x;
	return ss.str();
}

void execute(){
	
	int number =0;
	int supplied[30];
	memset(supplied , 0 ,sizeof(supplied));
	string temp = ""; //initializations

	for(int i =1 ; i <= G ; i++)
		if(profile[i]){
			number++;
			for(int j = 1 ; j <= V ; j++)
				supplied[j] += scoop[i][j]; 
			if(temp.size() != 0) temp += " ";
			temp += convert_string(i);
		}
	if(number < ans){
		for(int i = 1 ; i<= V ;i++)
			if(supplied[i] < vitamin[i]) goto rejected;
		sequence = temp;
		ans = number;
	}
	rejected:;
	
}

void solve(int index){
	if(index > G) {
		execute();
		return;
	}

	profile[index] = true;
	solve(index + 1);
	profile[index] = false;
	solve(index + 1);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	freopen("holstein.in" , "r" , stdin);
	freopen("holstein.out" , "w", stdout);
	cin >> V;
	for(int i = 1 ; i <= V ; i++)
		cin >> vitamin[i];
	cin >> G;
	for(int i = 1 ; i <= G ; i++)
		for(int j = 1;  j <= V ; j++)
			cin >> scoop[i][j];

	solve(1);
	cout << ans << " " << sequence << "\n";
	return 0;
}