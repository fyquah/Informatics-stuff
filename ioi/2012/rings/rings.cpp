#include <vector>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int , int> pii;

vector< vector<int> > adj;
vector <int> three_edges;
vector <int> four_edges;
bool no_possible_critical = false;

bool include(int haystack , int needle){
	for(int i = 0  ; i < adj[haystack].size() ; i++)
		if(adj[haystack][i] == needle) return true;
	return false;
}

bool bfs(int removed_node){
	
	bool visited[1000010];
	memset(visited[i] , 0 , sizeof visited);

	for(int root = 0 ; root < N ; root++){
		if(visited[root] || root == removed_node) continue;
		
		queue<int> bfs_queue;
		bfs_queue.push_back(root);
		
		while(!bfs_queue.empty()){
			int cur = bfs.front();
			bfs.pop();
			
			if(visited[cur] || cur == removed_node)
				continue;

			visited[cur] = true;

			if(adj[cur].size() >= 3 && !include(cur , removed_node)) return false;

			for(int i = 0 ; i < adj[cur].size() ; i++)
				if(!visited[adj[cur][i]] && adj[cur][i] != removed_node)
					bfs.push(adj[cur][i]);
		
		}
	}
	return true;
}

void Init(int N_) {
	N = N_;
	adj.resize(N);
}

void Link(int A, int B) {
	adj[A].push_back(B);
	adj[B].push_back(A);
	

	if(adj[A].size() == 3)
		three_edges.push_back(A);
	if(adj[B].size() == 3)
		three_edges.push_back(B);
		
	if(adj[A].size() == 4)
		four_edges.push_back(A);
	if(adj[B].size() == 4)
		four_edges.push_back(B);
	
	
	/*
	if(adj[A].size() >= 4){
		if(presence_of_4_edges_node)
			number_of_critical = 0;
		else {
			presence_of_4_edges_node = true;
			number_of_critical = 1;
		}
	}
	
	if(adj[B].size() >= 4){
		if(presence_of_4_edges_node)
			number_of_critical = 0;
		else
			presence_of_4_edges_node = true;
	}
	*/
}

int CountCritical() {
	if(four_edges.size() > 1)
		return 0;
		
	if(four_edges.size() != 0){
		if(bfs(four_edges[0])) return 1;
		else return 0;
	}
	
	else if(three_edges.size() != 0){
		int counter = 0;
		for(int i = 0  ; i < three_edges[0].size() ; i++)
			if(bfs(i)) counter++;
		return counter;
	}
	
	else if(){
	
	}
	
	else
		return N;
	
}
