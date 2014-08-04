#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#define SIZE_OF_TREE 20
using namespace std;

int ancestor[SIZE_OF_TREE][SIZE_OF_TREE];
int tree[SIZE_OF_TREE];
int level[SIZE_OF_TREE];
int N;

void preProcess(){
	//initialize all the levels
	level[0] = 1;
	for(int i = 1 ; i < N ; i++)
		level[i] = level[tree[i]] + 1;
	// done initializing the levels

	//code the ancestor table
	memset(ancestor , -1 , sizeof ancestor);
	for(int i = 0 ; i < N ; i++)
		ancestor[i][0] = tree[i];

	for(int j = 1 ; (1 << j) < N ; j++)
		for(int i = 0 ; i < N ; i++)
			if(ancestor[i][j-1] != -1)
				ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
}

int query(int p , int q){
	// without loss of generality that level[p] > level[q]
	if(level[p] < level[q]){
		int temp = p;
		p = q;
		q = temp;
	}

	int exponent = (int) log(level[p]) / log(2);

	// Now to 'decrease' the level of p so that it is at the same level as q
	for(int i = exponent ; i >= 0 ; i--){
		if(level[p] - (1 << i) >= level[q])
			p = ancestor[p][i];
	}
	cout << "Exponent is " << exponent << endl;
	cout << "p is " << p << endl;
	cout << "q is " << q << endl;
	
	if(p == q)
		return p;
	// now p and q are at the same level
	for(int i = exponent ; i >= 0 ; i--){
		if(ancestor[p][i] != ancestor[q][i] && ancestor[q][i] != -1 && ancestor[p][i] != -1)
			p = ancestor[p][i] , q = ancestor[q][i];
	}
	return tree[p];
}

int main()
{
	scanf("%d " , &N);
	for(int i =0 ; i < N ; i++)
		scanf("%d" , tree + i);
		
	preProcess();

	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; (1 << j) < N ; j++)
			printf("%d " , ancestor[i][j]);
		printf("\n");	
	}
	
	for(int i = 0 ; i < N ; i++)
		printf("%d's level is %d\n", i ,level[i]);

	while(true){
		int a,b;
		scanf("%d %d" , &a , &b);
		printf("%d\n", query(a,b));
	}
	
	return 0;
}
/*
int ancestor[SIZE_OF_TREE][SIZE_OF_TREE];
int tree[SIZE_OF_TREE];
int level[SIZE_OF_TREE];
int N;

void pre_process(){
	level[0] = 1;
	for(int i = 1 ; i < N ; i++){
		level[i] = level[tree[i]] + 1;
	}

	memset(ancestor , -1 , sizeof ancestor);
	
	for(int i = 0 ; i < N ; i++)
		ancestor[i][0] = tree[i];
		
	for(int j = 1 ; (1 << j) < N ; j++)
		for(int i = 0 ; i < N ; i++)
			if(ancestor[i][j-1] != -1)	
				ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
}

int query(int p , int q){
	if(level[p] < level[q]){
		int temp = p;
		p = q;
		q = temp;
	}

	int log2 = floor(log(level[p]) / log(2));
	// Finding log of level[p] , without the loss of generality that level[p] > level[q]

	//O(log N)
	for(int i = log2 ; i >= 0 ; i--)
		if(level[p] - (1 << i) >= level[q])
			p = ancestor[p][i];

	if(p == q)
		return p;
	//also O(log N)
	for(int i = log2 ; i >= 0 ; i--)
		if(ancestor[p][i] != ancestor[q][i] && ancestor[p][i] != -1)
			p = ancestor[p][i] , q = ancestor[q][i];

	return tree[p];
}

int main()
{
	scanf("%d " , &N);
	for(int i =0 ; i < N ; i++)
		scanf("%d" , tree + i);
		
	pre_process();
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; (1 << j) < N ; j++)
			printf("%d " , ancestor[i][j]);
		printf("\n");	
	}
	
	for(int i = 0 ; i < N ; i++)
		printf("%d's level is %d\n", i ,level[i]);

	printf("%d\n", query(5,12));
	return 0;
}
*/
