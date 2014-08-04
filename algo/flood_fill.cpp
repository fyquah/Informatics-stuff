#include <cstdio>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#define MAX 100

using namespace std;

int n;
string all[101];

bool visited[100][100];

int region_human;
int region_cow;

int solve(char index , int x, int y)
{
	if(visited[x][y] || all[x][y] != index) return 0;
	visited[x][y] = true;

	if(x > 0) solve(index , x-1 , y);
	if(y > 0) solve(index , x , y-1);
	if(x < n - 1) solve(index , x + 1 , y);
	if(y < n-1) solve(index , x , y + 1);

	return 1;
}


int main()
{
	//input
	ifstream fin("cowart.in");
	fin >> n;
	for(int i = 0 ;i < n ;i++)
		fin >> all[i];
	fin.close();

	//search for all human
	for(int i = 0 ; i < n ;i++)
		for(int j = 0 ;j < n ; j++)
			region_human += solve(all[i][j] , i , j);

	//make all the G into R
	for(int i = 0 ;i < n ;i++)
		for(int j = 0 ; j <n ;j++)
			if(all[i][j] == 'G') all[i][j] = 'R';
	//unvisit all the cells
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ;++j)
			visited[i][j] = false;

	for(int i = 0 ; i < n ;i++)
		for(int j = 0 ;j < n ; j++)
			region_cow += solve(all[i][j] , i , j);

	//search for cow

	ofstream fout("cowart.out");
	fout << region_human << " " << region_cow << "\n";

	fout.close();
	return 0;
}