#include <bits/stdc++.h>
#define GRAPH_SIZE 4

using namespace std;
typedef pair<int,int> pii;

priority_queue <pair<int , pii> > pq;
//pq.first is the weight
//pq.second.first is the parent node
//pq.second.second is the destination node
vector <vector <pii> > adj;
int tree[4 * GRAPH_SIZE];

void prims(int root){
	pq.push(make_pair(0,make_pair(-1,0)));
	
	bool visited[GRAPH_SIZE];
	memset(visited , false , sizeof visited);
	
	while(!pq.empty()){
		pair<int , pii> current = pq.top();
		pq.pop();
		int index = current.second.second;
		
		if(visited[index])
			continue;
		
		visited[index] = true;
		tree[index] = current.second.first;
	
		for(int i = 0 ; i < adj[index].size() ; i++){
			if(!visited[adj[index][i].second])
				pq.push(make_pair(adj[index][i].first , make_pair(index , adj[index][i].second)));
		}
	}
}

int main()
{
	int E;
	cin >> E;
	adj.resize(GRAPH_SIZE);
	for(int i = 0 ; i < E ; i++){
		int a,b,c;
		scanf("%d %d %d" , &a , &b , &c);
		adj[a].push_back(make_pair(b,c));
		adj[b].push_back(make_pair(a,c));
	}	
	
	memset(tree , -1 , sizeof tree);
	prims(0);

	for(int i = 0 ; i < GRAPH_SIZE ; i++)
		printf("%d's parent is %d\n" , i , tree[i]);
	
	return 0;
}
