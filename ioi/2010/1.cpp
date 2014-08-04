/*
ID: fy.q1
LANG: C++
TASK: taskname
*/
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

int a , b , c;

int Theory(int x , int y , int z)
{
	if(x == a && y == b && z == c)
		return 0;
	else
		while(true){
			int return_value = rand() % 3 + 1;
			if(return_value == 1 && a != x)
				return 1;
			else if (return_value == 2 && b != y)
				return 2;
			else if (return_value == 3 && c != z)
				return 3;	
		}
}

int Solve()
{
	int counter = 0;
	int m = 1;
	int l = 1;
	int w = 1;

	while(true){
		int k = Theory(m, l , w);
		if(k == 0)
			return ++counter;
		else if(k == 1)
			m++;
		else if(k == 2)
			l++;
		else if(k == 3)
			w++;
		counter++;
	}

}

int main(void)
{
	for(int i = 0 ; i < 10 ; i++){
		a = rand() % 6 + 1;
		b = rand() % 10 + 1;
		c = rand() % 6 + 1;
		cout << "You have completed this in " << Solve() << endl;
	}
	return 0;
}