#include <cstdio>
#include <algorithm>
#define GRAPH_SIZE 5
const int inf = 1 << 29;
int mat[GRAPH_SIZE][GRAPH_SIZE];

int main()
{
	for(int i = 0 ; i < GRAPH_SIZE ; i++)
		for(int j = 0 ; j < GRAPH_SIZE ;j++){
			if(i == j) mat[i][j] = 0;
			else mat[i][j] = inf;
		}
	int N;
	scanf("%d" , &N);
	for(int i = 0 ; i < N ; i++){
		int first_index , second_index , weight;
		scanf("%d %d %d" , &first_index , &second_index , &weight);
		mat[first_index][second_index] = weight;
		//mat[second_index][first_index] = weight;
		//adjacency_list[second_index].push_back(make_pair(weight , first_index));
	}

	for(int k = 0 ; k < GRAPH_SIZE ; k++)
		for(int i = 0 ; i < GRAPH_SIZE ; i++)
			for(int j = 0 ; j < GRAPH_SIZE ;j++)
				mat[i][j] = std::min(mat[i][j] , mat[i][k] + mat[k][j]);
				
	for(int i = 0 ;i <GRAPH_SIZE ;i++){
		for(int j = 0 ; j < GRAPH_SIZE ; j++)
			printf("%d -> %d has the weight %d\n" , i , j , mat[i][j]);
	}	
	return 0;
}

