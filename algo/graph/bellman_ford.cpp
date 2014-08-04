#include <cstdio>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>
#define GRAPH_SIZE 5
using namespace std;
const int inf  = 1 << 29;
typedef pair<int ,int> pii;

int dist[GRAPH_SIZE];
vector< vector< pii> > adjacency_list;

int main()
{
	adjacency_list.resize(GRAPH_SIZE);
	int N;
	scanf("%d" , &N);
	for(int i = 0 ; i < N ; i++){
		int first_index , second_index , weight;
		scanf("%d %d %d" , &first_index , &second_index , &weight);
		adjacency_list[first_index].push_back(make_pair(weight , second_index));	
		//adjacency_list[second_index].push_back(make_pair(weight , first_index));
	}
	
	for(int i = 0 ; i < GRAPH_SIZE ; i++)
		dist[i] = inf;
	dist[0] = 0;
	
	// Relax all the edges E times
	for(int i = 0 ; i < GRAPH_SIZE ; i++)
		for(int j = 0 ; j < GRAPH_SIZE ; j++)
			for(int k = 0 ; k < adjacency_list[j].size() ; k++)
				dist[adjacency_list[j][k].second] = min(dist[adjacency_list[j][k].second] , dist[j] + adjacency_list[j][k].first);

	for(int i = 0 ; i < GRAPH_SIZE ; i++)
		printf("dist[%d] = %d\n" , i , dist[i]);
}
