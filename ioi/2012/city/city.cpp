#include <cstring>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
#define MODULO 1000000000
#define MAX_N 5010
using namespace std;
typedef pair<int , int> pii;

vector< vector<int> > adj_list;
vector<pii> field;

int bfs(int root){
	int sum = 0;

	bool visited[MAX_N];
	memset(visited , 0 , sizeof(visited));
	queue <pii> bfs_queue;
	bfs_queue.push(make_pair(0,root));
	//first is distance , second is current_position
	while(!bfs_queue.empty()){
		pii cur = bfs_queue.front();
		bfs_queue.pop();

		if(visited[cur.second])
			continue;

		visited[cur.second] = true;
		sum = (sum + cur.first) % MODULO;

		for(int i = 0 ; i < adj_list[cur.second].size() ; i++)
			if(!visited[adj_list[cur.second][i]])
				bfs_queue.push(make_pair(cur.first + 1 , adj_list[cur.second][i]));
	}

	return (sum + MODULO) % MODULO;
}

int DistanceSum(int N, int *X, int *Y) {
	if(N > 2000){
		long long n = N;
		long long x[100010];
		long long y[100010];

		for(long long i = 0 ; i < n ; i++){
			x[i] = X[i];
			y[i] = Y[i];
		}

		long long sum = 0;
		sort(x , x + n);
		sort(y , y + n);

		for(long long i = N -1 ; i >= 0 ; i--)
			sum = (sum + i * x[i] - (n-1-i) * x[i] + MODULO) % MODULO;

		for(long long i = N -1 ; i >= 0 ; i--)
			sum = (sum + i * y[i] - (n-1-i) * y[i] + MODULO) % MODULO;

		return (sum + MODULO) % MODULO;
	}

	int sum = 0;

	adj_list.resize(N);

	for(int i = 0 ; i < N ; i++)
		field.push_back(make_pair(X[i] , Y[i]));

	// for(int i = 0 ; i < N ; i++)
	// 	cout << field[i].first << " " << field[i].second << endl;

	// use O(N^2) time to construct adjacency list
	for(int i = 0 ; i < N ; i++)
		for(int j = 0 ; j < N ; j++)
			if(i != j && ((abs(field[i].first - field[j].first) == 1 && field[i].second == field[j].second ) || (abs(field[i].second - field[j].second) == 1 && field[i].first == field[j].first)))
				adj_list[i].push_back(j);

	// for(int i = 0 ; i < N ; i++){
	// 	cout << i << " -> " << endl;
	// 	for(int j = 0 ; j < adj_list[i].size() ; j++)
	// 		cout << adj_list[i][j] << " ";
	// 	cout << endl;
	// }

	for(int i = 0 ; i < N ; i++)
		sum = (sum + bfs(i)) % MODULO;

	return ((sum/2) % MODULO);
}
