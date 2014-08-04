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

using namespace std;

int HC(int N){
	int lo = 1;
	int hi = N;
	int prev = 1;

	bool isLow = true; //tells us lo or hi was the one tested the last time round.

	Guess(lo);

	while(true){
		int cur = (isLow?hi:lo);
		int temp = Guess(cur);
		isLow = !isLow; //isLow now indicates whether the current Guess request is from high or low.
		int mid = (lo+hi)/2;

		if(temp == 0)
			return (prev+cur)/2;
		else if(temp == 1) { //nearer to the current request
			if(isLow) hi = mid;
			else lo = mid;
		}
		else if(temp == -1){ //nearer to the previous request
			if(isLow) lo = mid;
			else hi = mid;
		}

		prev = cur;
	}

}

int main()
{

	return 0;
}