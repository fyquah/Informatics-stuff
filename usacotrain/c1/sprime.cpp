/*

ID: fy.q1
LANG: C++
TASK: sprime
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

FILE *fout;
FILE *fin;
int n;
long x;
int k;
vector <long> ans;
vector <long> temp;

bool isprime(long x){
	if(x == 1) return false;
	if(x == 2) return true;
	if(x %2 == 0) return false;
	for(long i = 3 ; i* i <= x ; i+= 2){
		if(x % i == 0) return false;
	}
	return true;
}

long raise_power(int base, int exponent){
	int x = base;
	for(int i = 1 ; i < exponent ;i++){
		x = x * base;
	}
	return x;
}

int main()
{
	x = 1;
	k = 2;
	fin = fopen("sprime.in", "r");
	fout = fopen("sprime.out", "w");

	fscanf(fin, "%d", &n);

	for(int i = 1 ; i < n ; i++)
		x = x * 10;

	if(x == 1){
		fprintf(fout,"%d\n%d\n%d\n%d\n",2,3,5,7);
		return 0;
	}

	ans.push_back(2);
	ans.push_back(3);
	ans.push_back(5);
	ans.push_back(7);

	while(k <= n){
		for(long i = 0 ; i < ans.size() ; i++)
			for(long j = 1 ; j <= 9 ; j+=2){
				if(j == 5) continue;
				if(isprime(ans[i] * 10 + j)) temp.push_back(ans[i] * 10 + j);
			}

		ans.clear();
		for(int i = 0 ; i < temp.size() ; i++){
			ans.push_back(temp[i]);
		}
		temp.clear();
		k++;
	}
	
	for(int i = 0 ; i < ans.size() ; i++)
		fprintf(fout,"%ld\n",ans[i]);

	return 0;
}