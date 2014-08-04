#include <cstdio>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>
#define GRAPH_SIZE 5
using namespace std;
typedef pair<int , int> pii;

const int inf = 1 << 29;

vector< vector <pii> > adjacency_list;
int dist[GRAPH_SIZE];
bool visited[GRAPH_SIZE];
priority_queue< pii , vector<pii> , std::greater<pii> > pq;

int main(){
memset(visited , 0 , sizeof visited);
	adjacency_list.resize(GRAPH_SIZE);
	int N;
	scanf("%d" , &N);
	for(int i = 0 ; i < N ; i++){
		int first_index , second_index , weight;
		scanf("%d %d %d" , &first_index , &second_index , &weight);
		adjacency_list[first_index].push_back(make_pair(weight , second_index));	
		//adjacency_list[second_index].push_back(make_pair(weight , first_index));
	}

	
	for(int i = 0; i < GRAPH_SIZE ; i++)
		dist[i] = inf;
	dist[0] = 0;
	pq.push(make_pair(0,0));

	while(!pq.empty()){
		pii cur_node = pq.top();
		pq.pop();
		
		int d = cur_node.first;
		int v = cur_node.second;
		
		if(dist[v] < d && visited[v])
			continue;
		
		visited[v] = true;
		
		for(int i = 0 ;i < adjacency_list[v].size() ; i++){
			dist[adjacency_list[v][i].second] = min(dist[adjacency_list[v][i].second] , d + adjacency_list[v][i].first);
			pq.push(make_pair(dist[adjacency_list[v][i].second], adjacency_list[v][i].second));
		}
	}

	for(int i = 0 ; i < GRAPH_SIZE ; i++)
		printf("dist[%d] = %d\n" , i , dist[i]);

	return 0;
}

/*
#include <cstdio>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>
#include <functional>
#include <cstring>
#define GRAPH_SIZE 5 
using namespace std;
typedef pair<int ,int> pii;
const int inf = 1 << 29;

vector< vector <pii> > adjacency_list;
int dist[GRAPH_SIZE];
bool visited_nodes[GRAPH_SIZE];
priority_queue<pii , vector<pii> , greater<pii> > pq;
// first is the distance from the root node
// second is the index of the node

int main()
{
	adjacency_list.resize(GRAPH_SIZE);
	
	memset(visited_nodes , 0 , sizeof visited_nodes);
	// let 0 be the root
	
	int N;
	scanf("%d" , &N);
	for(int i = 0 ; i < N ; i++){
		int first_index , second_index , weight;
		scanf("%d %d %d" , &first_index , &second_index , &weight);
		adjacency_list[first_index].push_back(make_pair(weight , second_index));	
		//adjacency_list[second_index].push_back(make_pair(weight , first_index));
	}
	
	for(int i = 1 ; i < GRAPH_SIZE ; i++)
		dist[i] = inf;
	dist[0] = 0;
	
	
	pq.push(make_pair(0,0));
	
	while(!pq.empty()){
		pii cur_node = pq.top();
		pq.pop();
		
		int d = cur_node.first;
		int v = cur_node.second;
		
		if(visited_nodes[v])
			continue;
		
		visited_nodes[v] = true;
		
		for(int i = 0 ; i < adjacency_list[v].size() ; i++){
			dist[adjacency_list[v][i].second] = min(dist[adjacency_list[v][i].second] , adjacency_list[v][i].first + d);
			pq.push(make_pair(d + dist[adjacency_list[v][i].second] , adjacency_list[v][i].second));
		}
	}
	
	for(int i = 0 ; i < GRAPH_SIZE ; i++)
		printf("dist[%d] = %d\n" , i , dist[i]);	
	
	return 0;
}
*/
