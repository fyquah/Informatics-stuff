#include <stdio.h>
#include <stack>
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


void dfs(int root){
	stack <Node> dfs_stack;
	dfs_stack.push(Node(root , 0));
	bool visited_nodes[GRAPH_SIZE];

	memset(visited_nodes , 0 , sizeof visited_nodes);

	while(!dfs_stack.empty()){
		Node cur = dfs_stack.top();
		dfs_stack.pop();
		if(visited_nodes[cur.index])
			continue;
		visited_nodes[cur.index] = true;

		// Do your stuff here

		for(int i = 0 ; i < adjacency_list[cur.index].size() ; i++)
			if(!visited_nodes[adjacency_list[cur.index][i].first])
				dfs_stack.push(Node(adjacency_list[cur.index][i].first , adjacency_list[cur.index][i].second + cur.cost));
	}
}

int main()
{
	adjacency_list.resize(GRAPH_SIZE , vector<pii>());
	dfs(0);
	return 0;
}