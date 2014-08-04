#include"station.h"
#include <vector>
#include <iostream>
using namespace std;

int findMinDays(int n, int k, int lodge[])
{
	vector <int> good_spots;
	for(int i = 0 ; i < n ; i++)
		if(lodge[i])
			good_spots.push_back(i);
	
	/*
	for(int i = 0 ; i < good_spots.size() ; i++)
		cout << good_spots[i] << " ";
	cout << "\n";
	*/

	int cur_location = 0;
	int min_days = 1;
	
	for(int i = 1 ; i < good_spots.size() ; i++){
		if(good_spots[i] - good_spots[cur_location] > k){
			if(i - 1 == cur_location) // impossible to continue journey
				return -1;
			else {
				cur_location = i - 1;
				min_days++;
				i--;
			}
		}
	}
	
	return min_days;
}
