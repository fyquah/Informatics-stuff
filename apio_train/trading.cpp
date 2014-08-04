#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int N, M;
int start[300030];
int end[300030];
int price[300030];
int value[300030];
int tree[1500030];
int lazy[1500030];
bool visited[300030];

int get(int index , int cur_lo , int cur_hi , int node)
{
	if(lazy[node] != 0) {
		tree[node] = max(lazy[node],tree[node]);
		if(cur_lo != cur_hi){
			lazy[node*2+1] = max(lazy[node*2+1] , lazy[node]);
			lazy[node*2+2] = max(lazy[node*2+2] , lazy[node]);
		}
		lazy[node] =0;
	}
	if(cur_lo > index || cur_hi < index) return 0;
	if(cur_lo == cur_hi)
		return tree[node];
	return max(get(index,cur_lo,(cur_lo+cur_hi)/2,node*2+1) , get(index,(cur_hi+cur_lo)/2 + 1 , cur_hi, node*2 +2));
}

void update(int lo, int hi, int val ,int cur_lo, int cur_hi,int node)
{
	if(lazy[node] != 0){
		tree[node] = max(lazy[node],tree[node]);
		if(cur_lo != cur_hi){
			lazy[node*2 + 1] = max(lazy[node*2+1] , lazy[node]);
			lazy[node*2 + 2] = max(lazy[node*2+2] , lazy[node]);
		}
		lazy[node] = 0;
	}

	if(lo > cur_hi || hi < cur_lo || lo > hi) return;

	if(cur_lo >= lo && cur_hi <= hi){
		tree[node] = max(tree[node],val);
		if(cur_lo != cur_hi){
			lazy[node*2 + 1] = max(lazy[node*2+1],val);
			lazy[node*2 + 2] = max(lazy[node*2+2],val);
		}
		return;
	}
	update(lo,hi,val,cur_lo,(cur_lo+cur_hi)/2,node*2+1);
	update(lo,hi,val,(cur_hi+cur_lo)/2 + 1,cur_hi, node*2+2);
	tree[node] = max(tree[node*2+1],tree[node*2+2]);
}

int main()
{
	memset(visited,0,sizeof(visited));
	memset(tree,0,sizeof(tree));
	memset(lazy,0,sizeof(lazy));
	freopen("trading.in" , "r" , stdin);
	freopen("trading.out" , "w" , stdout);
	scanf("%d %d" , &N , &M);
	for(int i = 1 ; i<= M ; i++)
		scanf("%d %d %d",start+i,end+i,price+i);
	for(int i = 1 ; i<= M ; i++)
		value[i] = price[i] + (N - start[i]);

	for(int i = 1 ; i <= M ; i++){
		update(start[i], end[i], value[i], 1, N, 0);
		memset(visited+start[i] , true, end[i] - start[i] +1);
	}
		
	for(int i = 1 ; i <= N ; i++){
		if(i > 1) printf(" ");
		printf("%d",(visited[i]?get(i,1,N,0)+(i-N):0));
	}
	printf("\n");
	return 0;
}