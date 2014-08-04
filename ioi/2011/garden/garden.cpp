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

//N is the numeber of Nodes
//M is the number of edges
//P is the number of 
void count_routes(int N , int M , int P , int R[][2] , int Q , int G[])
{
	vector<set <int> > graph(N);
	for(int i = 0 ; i < M ; i++){
		graph[R[i][0]].insert(R[i][1]);
		graph[R[i][1]].insert(R[i][0]);
	}

	for(int i = 0 ; i < Q ; i++) {
		int ans = 0;

		

		answer(ans);
	}
}