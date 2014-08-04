# include <iostream>
# include <fstream>
# include <algorithm>
# include <utility>
# include <vector>
# include <string>
# include <stdio.h>
# include <string>
# include <stdlib.h>
# include <sstream>
# include <math.h>
# include <set>
# include <cstring>
using namespace std;

bool test(int m , int r , int c , int h , int w , int q[][]){
	int cumulative[3012][3012];
	memset(cumulative , 0 , sizeof(cumulative));

	for(int i = 0 ; i < r ; i++)
		for(int j = 0 ; j < c ; ++j) {
			if(q[i][j] > m) cumulative[i][j] = 1;
			else if(q[i][j] < m) cumulative[i][j] = -1;
			else cumulative[i][j] = 0;
		}

	for(int i = 1;  i <= r ; i++)
		for(int j = 1; j <= c ; j++)
			cumulative[i][j] = q[i-1][j-1] + cumulative[i-1][j] + cumulative[i][j-1] - cumulative[i-1][j-1];

	// i and j refers to the bottom right corner of the rectangle
	for(int i = h ; i <= r ; i++)
		for(int j = c ; j <= c ; j++){
			if(cumulative[i][j] - cumulative[i][j-c] - cumulative[i-r][j] + cumulative[i-r][j-c]  <= 0) return true;
		}

	return false;
}

int rectangle(int r , int c, int h , int w ,  int q[][]){
	//binary search for the answer
	int lo = 1;
	int hi = r * c;
	int mid;
	while(lo != hi){
		mid = (lo+hi)/2;
		if(test(mid , r , c , h , w , q)) hi = mid;
		else lo = mid+1;
	}
	return lo;
}