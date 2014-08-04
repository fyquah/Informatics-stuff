#include <bits/stdc++.h>
#define GRAPH_SIZE 100
using namespace std;

int tree[GRAPH_SIZE];
int level[GRAPH_SIZE];
int ancestor[GRAPH_SIZE][GRAPH_SIZE];

void preProcess(const int N){
	level[0] = 1;
	for(int i = 1 ; i < N ; i++)
		level[i] = level[tree[i]] + 1;
		
	for(int i = 0 ; i < N ; i++)
		ancestor[i][0] = tree[i];
		
	memset(ancestor , -1 , sizeof ancestor);
		
	for(int j = 0 ; (1 << j) < N ; j++)
		for(int i = 0 ; i < N ; i++)
			if(ancestor[i][j-1] != -1)
				ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
}

int query(int p , int q){
	if(level[p] < level[q]){
		p = p ^ q;
		q = p ^ q;
		p = p ^ q;
	}
	int exponent = floor(log(level[p]) / log(2));
	
	//normalize their levels
	for(int i = exponent ; i > 0 ; i--)
		if(level[p] - i >= level[q])
			p = ancestor[p][i];
	
	// now that p and q are at the same level
	cout << p << " " << q << endl;
	if(p == q)
		return p;
	
	for(int i = exponent ; i >= 0 ; i--)
		if(ancestor[p][i] != ancestor[q][i])
			p = ancestor[p][i] , q = ancestor[q][i];
	
	return tree[p];
}

int main()
{
	int N;
	scanf("%d" , &N);
	for(int i = 0 ; i < N ; i++)
		scanf("%d" , &tree[i]);
	preProcess(N);	
	puts("Level :\n");
	for(int i = 0 ;i < N ; i++)
		printf("%d " , level[i]);
	while(true){
		int a,b;
		scanf("%d %d" , &a , &b);
		printf("%d\n" , query(a,b));
	}
	return 0;
}
