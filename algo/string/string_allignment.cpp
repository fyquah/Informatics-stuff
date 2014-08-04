/*
The String Alignment (or Edit Distance) problem is defined as follows: Given two strings A and B,
align 1 A with B with the maximum alignment score (or minimum number of edit operations):
After aligning A with B, there are few possibilities between character A[i] and B[i] ∀ index i:
1. Character A[i] and B[i] match (assume we give ‘+2’ score),
2. Character A[i] and B[i] mismatch and we replace A[i] with B[i] (‘-1’ score),
3. We insert a space in A[i] (also ‘-1’ score), or
4. We delete a letter from A[i] (also ‘-1’ score).
*/
#include <iostream>
#include <string>
using namespace std;

int mat[200][200];

int main()
{
	ios::sync_with_stdio(false);
	string str_a;
	string str_b;
	cin >> str_a >> str_b;
	
	str_a = " " + str_a;
	str_b = " " + str_b;
	
	for(int i = 0 ; i < str_a.length() ; i++){
		for(int j = 0 ;j < str_b.length() ; j++){
			if(i == 0 && j == 0){
				mat[i][j] = 0;
				continue;
			}
			if(str_a[i] == str_b[j]){
				if(i > 0 && j > 0) mat[i][j] =  mat[i-1][j-1] + 2;
				else mat[i][j] = 2;
			}
			else {
				if(i > 0 && j > 0) {
					mat[i][j] = max(mat[i-1][j] , mat[i][j-1]);
					mat[i][j] = max(mat[i-1][j-1] , mat[i][j]);
					mat[i][j] -= 1;	
				}
				else if(i > 0) mat[i][j] = mat[i-1][j] -1;
				else if(j > 0) mat[i][j] = mat[i][j-1] -1;
				else mat[i][j] = -1;
			}
		}
	}
	
	for(int i = 0  ;i < str_a.length() ; i++){
		for(int j =0 ; j < str_b.length() ; j++){
			cout << mat[i][j] << " ";
		}	
		cout << endl;
	}
	
	return 0;
}

/*
for(int i = 0 ; i < str_a.length() ; i++){
		for(int j = 0 ; j < str_b.length() ; j++){
			if(str_a[i] == str_b[j]){
				if(i > 0 && j > 0) mat[i][j] = mat[i-1][j-1] + 2;
				else mat[i][j] = 2;
			}
			else {
				if(i > 0 && j > 0) mat[i][j] = max(mat[i-1][j] , mat[i][j-1]) - 1;
				else if (i > 0) mat[i][j] = mat[i-1][j] -1;
				else if (j > 0) mat[i][j] = mat[i][j-1] -1;
				else mat[i][j] = -1;
			}
		}
	} 
	
	for(int i = 0  ;i < str_a.length() ; i++){
		for(int j =0 ; j < str_b.length() ; j++){
			cout << mat[i][j] << " ";
		}	
		cout << endl;
	}
*/
