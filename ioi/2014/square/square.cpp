#include"square.h"
#include <string.h>
#include <algorithm>
using namespace std;
int cumulative_matrix[1010][1010];

int findMaxSquare(int material[SIZE][SIZE], int materialSize)
{
	int best_area = 0;
	int counter = 0;
	
	for(int i = 0 ; i < materialSize ; i++){
		for(int j = 0 ; j < materialSize ; j++){
			if(material[i][j] == 0) {
				cumulative_matrix[i][j] = 0;
			} 
			else {
				if(i > 0 && j > 0) 
					cumulative_matrix[i][j] = 1 + min(cumulative_matrix[i-1][j-1] , min(cumulative_matrix[i][j-1] , cumulative_matrix[i-1][j]));
				else
					cumulative_matrix[i][j] = 1;
					
				if(cumulative_matrix[i][j] == best_area)
					counter++;
				else if(cumulative_matrix[i][j] > best_area){
					best_area = cumulative_matrix[i][j];
					counter = 1;
				}
			}			
		}
	}

	return best_area * counter;
}
