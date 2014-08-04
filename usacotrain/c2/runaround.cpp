/*
ID: fy.q1
LANG: C++
TASK: runround
*/
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int lamps[10010];
vector <string> ans;

int main()
{
	uint M;
	
	ios_base::sync_with_stdio(false);
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	scanf("%d" ,  &N);
	scanf("%d" , &C);
	int a = 0;
	while(a != -1){
		lamps[a] = 1;
		scanf("%d" , &a);
	}
	a = 0;
	while(a != -1){
		lamps[a] = -1;
		scanf("%d" , &a);
	}

	for(int p = 0 ; p < 2 ; p++)
		for(int q = 0 ; q < 2 ; q++)
			for(int r = 0 ; r < 2 ; r++)
				for(int s = 0 ; s < 2 ; s++){
					if(p+q+r+s > C) continue;
					int b[7] = {0 , 1 , 1, 1 ,1 , 1 , 1};
					if(p) for(int i = 1 ; i <= 6 ; i++)
							b[i] = !b[i];
					if(q) for(int i = 1 ; i <= 6 ; i+=2)
							b[i] = !b[i];
					if(r) for(int i = 1 ; i <= 6 ; i+=2)
							b[i] = !b[i];
					if(s) for(int i = 1 ; i <= 6 ; i+=3)
							b[i] = !b[i]
					

					rejected;
				}
					

	if(!ans.empty()){

	}
	else {
		printf("IMPOSSIBLE\n");
	}

	return 0;
}