#include <cstdio>
#include <cstring>
#include <utility>
#include <cmath>
#include <queue>
#include <vector>
#define NUMBER_OF_NODES 5
#define NUMBER_OF_EDGES 7
using namespace std;
typedef pair<int ,int> pii;

priority_queue< pair<int , pii>  , vector<pair<int , pii> > , greater< pair<int , pii> > >EdgeList;

int set[NUMBER_OF_NODES];

int findSet(const int ori_node){
	int node = ori_node;

	while(set[node] >= 0)
		node = set[node];

	if(node != ori_node)
		set[ori_node] = node;

	return node;
}

void unionSet(const int ori_node_a , const int ori_node_b){
	int node_a = ori_node_a;
	int node_b = ori_node_b;

	while(set[node_a] >= 0)
		node_a = set[node_a];

	while(set[node_b] >= 0)
		node_b = set[node_b];

	if(abs(set[node_b]) > abs(set[node_a])){
		set[node_a] = set[ori_node_a] = node_b;
		set[node_b] -= 1;
		set[ori_node_b] = (node_b != ori_node_b) ? node_b : set[node_b];
	}
	else{
		set[node_b] = set[ori_node_b] = node_a;
		set[node_a] -= 1;
		set[ori_node_a] = (node_a != ori_node_a) ? node_a : set[node_a];
	}
}

int main()
{
	memset(set , -1 , sizeof set);

	for(int i = 0 ; i < NUMBER_OF_EDGES ; i++){
		int a, b, c;
		scanf("%d %d %d" , &a , &b , &c);
		EdgeList.push(make_pair(c , make_pair(a, b)));
	}

	int mst_cost = 0;

	while(!EdgeList.empty()){
		pair<int , pii> cur_edge = EdgeList.top();
		EdgeList.pop();

		if(findSet(cur_edge.second.first) == findSet(cur_edge.second.second))
			continue;

		printf("Joining the edges %d and %d with the weight %d\n" , cur_edge.second.first , cur_edge.second.second , cur_edge.first);
		unionSet(cur_edge.second.first , cur_edge.second.second);

		mst_cost += cur_edge.first;
	}

	printf("The cost of the mst is %d\n" , mst_cost);
}
