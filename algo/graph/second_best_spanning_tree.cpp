#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <functional>
#define NUMBER_OF_EDGES 7
using namespace std;

typedef pair<int , int> pii;

// UNION DISJOINT SET ALGO
int set[NUMBER_OF_EDGES];

void unionSet(const int ori_node_a , const int ori_node_b){
	int node_a = ori_node_a;
	int node_b = ori_node_b;
	
	while(set[node_a] >= 0)
		node_a = set[node_a];
	while(set[node_b] >= 0)
		node_b = set[node_b];
		
	if(set[node_b] < set[node_a]){
		set[node_a] = set[ori_node_a] = node_b;
		if(node_b != ori_node_b)
			set[ori_node_b] = node_b; 
	}
	else {
		set[node_b] = set[ori_node_b] = node_a;
		if(node_a != ori_node_a)
			set[ori_node_a] = node_a;	
	}
}

int findSet(const int ori_node_a){
	int node_a = ori_node_a;

	while(set[node_a] >= 0)
		node_a = set[node_a];
	
	if(node_a != ori_node_a)
		set[ori_node_a] = node_a;
	
	return node_a; 
}

// END OF DISJOINT SET ALGO

priority_queue< pair<int , pii> , vector< pair<int , pii> > , std::greater< pair<int , pii> > > EdgeList;

vector< pair<int , pii> > mst_edge_list;
vector< pair<int , pii> > all_edge_list;

int main()
{
	memset(set , -1 , sizeof set);
	for(int i = 0 ; i < NUMBER_OF_EDGES ; i++){
		int a, b, c;
		scanf("%d %d %d" , &a , &b , &c);
		all_edge_list.push_back(make_pair(c , make_pair(a,b)));
		EdgeList.push(make_pair(c , make_pair(a,b)));
	}
	
	// Creating the MST
	int mst_cost = 0;
	while(!EdgeList.empty()){
		pair<int , pii> cur_edge = EdgeList.top();
		EdgeList.pop();
		if(findSet(cur_edge.second.first) == findSet(cur_edge.second.second))
			continue;
		
		unionSet(cur_edge.second.second , cur_edge.second.first);
		mst_edge_list.push_back(cur_edge);
		
		mst_cost += cur_edge.first;
	}
	printf("The minimum spanning tree is %d\n" , mst_cost);
	for(int i = 0 ; i < mst_edge_list.size() ; i++){
		printf("%d and %d with the weight %d\n" , mst_edge_list[i].second.second , mst_edge_list[i].second.first   , mst_edge_list[i].first);
	}
	// Finish creating the MST
	
	/*
	To create the Second Minimum Spanning tree
	Test all the edges in the minimum spanning tree by replacing their weight with infinity;
	Re run the above algorithm
	Then just get the one with the minimum cost, that is the second best
	Complexity = O(ElogE + E + V)
	*/
}
