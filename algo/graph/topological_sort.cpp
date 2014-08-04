//Make sure it is a directed Acyclic Graph before attempting to do topological sort
#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
typedef pair<int , int> pii;

vector<int> sequence;
vector< vector<pii> > adjacency_list;

void dfs(int root , bool * visited_nodes){
	if(visited_nodes[root])
		return;
		
	stack<int> dfs_stack;
	dfs_stack.push(root);
	
	while(!dfs_stack.empty()){
		int cur = dfs_stack.top();
		dfs_stack.pop();
		
		if(visited_nodes[cur])
			continue;
		
		visited_nodes[cur] = true;
		
		sequence.push_back(cur);
		
		for(vector<pii>::iterator it = adjacency_list[cur].begin() ; it != adjacency_list[cur].end() ; it++)
			if(!visited_nodes[it->first])
				dfs_stack.push(it->first);
	}
		
	return;
}

int main()
{
	int N , E;
	scanf("%d %d" , &N , &E);
	sequence.clear();
	adjacency_list.resize(N);

	for(int i = 0 ; i < E ; i++) {
		int a,b,c;
		scanf("%d %d %d" , &a , &b , &c);
		adjacency_list[a].push_back(make_pair(b,c));
	}
	
	bool visited_nodes[10];
	memset(visited_nodes , 0 , sizeof visited_nodes);
	for(int i = 0 ; i < N ; i++)
		if(!visited_nodes[i])
			dfs(0 , visited_nodes);

	for(int i = 0 ; i < sequence.size() ; i++)
		printf("%d " , sequence[i]);
	printf("\n");
	
	return 0;
}
