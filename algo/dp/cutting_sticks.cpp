/*
Given a stick of length 1 ≤ l ≤ 1000, make 1 ≤ n ≤ 50 cuts to that sticks 
(coordinates within range (0 . . . l) are given). 
The cost of cut is determined by the length of the stick to be cut. 
Find a cutting sequence so that the overall cost is minimized!
*/
#include <cstdio>
#include <algorithm>
const int inf = 1 << 20;

int N = 3;
int L = 100;
int cost = 0;
int coordinates[55] = {0 , 25 , 50 , 75 , 100};

int cut(int left , int right){
	int segment = inf;
	if(left + 1 == right)
		return 0;

	for(int i = left + 1 ; i < right ; i++){
		segment = std::min(segment , cut(left , i) + cut(i, right) + coordinates[right] - coordinates[left]);
	}

	return segment;
}

int main()
{
	std::sort(coordinates , coordinates + N + 2);
	cost = cut(0,N+1);
	printf("The mininum price is to cut is %d\n" , (cost));
	return 0;	
}