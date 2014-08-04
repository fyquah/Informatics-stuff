#include <stdio.h>
#include <queue>
#include <string.h>
#include <utility>
#include <vector>
#define GRAPH_SIZE 100
using namespace std;

typedef pair<int , int> pii;
// first is index
// second is weight
vector<vector<pii> > adjacency_list;

class Node {
public:
	int index;
	int cost;

	Node(int a , int b) : index(a) , cost(b) {}

	bool operator<(const Node & other){
		return cost < other.cost;
	}
	bool operator>(const Node & other){
		return cost > other.cost;
	}
};

bool operator<(const Node & first , const Node & second){
	return first.cost < second.cost;
}

bool operator> (const Node & first , const Node & second){
	return first.cost > second.cost;
}


void bfs(int root){
	queue <Node> bfs_queue;
	bfs_queue.push(Node(root , 0));
	bool visited_nodes[GRAPH_SIZE];

	memset(visited_nodes , 0 , sizeof visited_nodes);

	while(!bfs_queue.empty()){
		Node cur = bfs_queue.front();
		bfs_queue.pop();
		if(visited_nodes[cur.index])
			continue;
		visited_nodes[cur.index] = true;

		// Do your stuff here

		for(int i = 0 ; i < adjacency_list[cur.index].size() ; i++)
			if(!visited_nodes[adjacency_list[cur.index][i].first])
				bfs_queue.push(Node(adjacency_list[cur.index][i].first , adjacency_list[cur.index][i].second + cur.cost));
	}
}

int main()
{
	adjacency_list.resize(GRAPH_SIZE , vector<pii>());
	bfs(0);
	return 0;
}