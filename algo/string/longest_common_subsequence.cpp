#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int best[10][10];

int main()
{
	string x = "ABAZDC";
	string y = "BACBAD";
	for(int i = 1 ; i <= x.length() ; i++)
		for(int j = 1 ; j <= y.length() ; j++) {
			if(x[i-1]==y[j-1])
				best[i][j] = 1 + best[i-1][j-1];
			else 
				best[i][j] = max(best[i-1][j],best[i][j-1]);
		}
	for(int i = 1 ; i <= x.length() ; i++){
		for(int j = 1 ; j <= y.length() ; j++)
			cout << best[i][j] << " ";
		cout << "\n";
	}


}