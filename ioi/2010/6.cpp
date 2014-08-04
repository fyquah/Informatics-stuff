//a good implementation available http://codegolf.stackexchange.com/questions/3047/help-with-an-ioi-problem
#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <list>
#include <set>

using namespace std;
const int inf = 1 << 30;

//N is the number of cities
//P -> gives information on number of fans in each city, 0..N-1
//S[] and D[] are the list of nodes

int visit(bool * visited , int * total , const int * graph , const int * people, int node){
	if(visited[node]) return 0;
	visited[node] = true;
	int sum = 0;

	for(int i = 0 ; i < graph[node].size() ; i++)
		sum += visit(graph[node][i]);

	sum += people[node];
	total[node] = sum;
	return sum;
}

int LocateCentre(int N , int P[] , int S[] , int D[]){
	std::vector< set <int> > graph(N);
	for(int i = 0 ; i < N ; i++){
		graph[S[i]].insert(D[i]);
		graph[D[i]].insert(S[i]);
	}

	//carry out a dfs
	bool visited[N];
	memset(visited , false , sizeof(visited));
	stack <int> p;
	
	total[0] = visit(visited , total , graph , P, 0);

	//let node 0 be the root node
	memset(visited , false , sizeof(visited));
	int ans = inf;
	for(int i = 0 ; i < N ; i++){
		int cur = 0;
		cur = sum[0] = sum[i];
		for(int j = 0 ; j < graph[i].size() ; j++){
			if(visited[j] = true) continue;
			visited[j] = true;
			cur = max(graph[i][j] , cur);
		}
		ans = min(ans , cur);
	}
	return ans;
}

int main(){

	return 0;
}