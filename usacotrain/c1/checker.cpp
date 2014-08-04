/*

ID: fy.q1
LANG: C++
TASK: checker
*/
# include <iostream>
# include <fstream>
# include <algorithm>
# include <utility>
# include <vector>
# include <string>
# include <stdio.h>
# include <string>
# include <stdlib.h>
# include <sstream>
# include <math.h>

using namespace std;

FILE *fout;
FILE *fin;
int n;
int m;
int board[14][14]; //board[row][column]
int ans[14];
bool special = false;

void search(int x)
{
	if (x > n){
		m++;
		if(special) m++;
		if(m > 3)return;

		for(int i = 1 ; i <= n ; i++){
			fprintf(fout,"%d", ans[i]);
			if(i < n) fprintf(fout , " ");
		}
		fprintf(fout , "\n");
		return;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		if(board[x][i] != 0) continue;
		for(int k = 1 ; k <= n; k++){
			board[k][i]++;
		}

		for(int k = 1 ; x-k >=1 && (i-k) >= 1; k++){
			board[x-k][i-k]++;
		}

		for(int k = 1 ;x+k <= n && (i+k) <= n ; k++){
			board[x+k][i+k]++;
		}

		for(int k = 1 ;x-k >=1 && (i+k) <= n ; k++){
			board[x-k][i+k]++;
		}

		for(int k = 1 ;x+k <= n && (i-k) >= 1 ; k++){
			board[x+k][i-k]++;
		}

		ans[x] = i; //denotes that there is already something there
		search(x + 1);

		for(int k = 1 ; k <= n; k++){
			board[k][i]--;
		}

		for(int k = 1 ;x-k >= 1 && (i+k) <= n ; k++){
			board[x-k][i+k]--;
		}

		for(int k = 1 ;x+k <= n && (i-k) >= 1 ; k++){
			board[x+k][i-k]--;
		}

		for(int k = 1 ; x-k >=1 && (i-k) >= 1; k++){
			board[x-k][i-k]--;
		}

		for(int k = 1 ;x+k <= n && (i+k) <= n ; k++){
			board[x+k][i+k]--;
		}
	}
}

int main(void)
{
   fin = fopen("checker.in", "r");
   fout = fopen("checker.out", "w");

   fscanf(fin, "%d", &n);
   //place a queen at a box at the first row
   // carry out recursion
   if(n == 6){
	search(1);
   fprintf(fout , "%d\n", m);
   return 0;
   }	
   else
   {
	for(int i = 1 ; i <= (n)/2 ; i++)
		{
			if(board[1][i] != 0) continue;

			for(int k = 1 ; k <= n; k++){
				board[k][i]++;
			}

			for(int k = 1 ; 1-k >=1 && (i-k) >= 1; k++){
				board[1-k][i-k]++;
			}

			for(int k = 1 ;1+k <= n && (i+k) <= n ; k++){
				board[1+k][i+k]++;
			}

			for(int k = 1 ;1-k >=1 && (i+k) <= n ; k++){
				board[1-k][i+k]++;
			}

			for(int k = 1 ;1+k <= n && (i-k) >= 1 ; k++){
				board[1+k][i-k]++;
			}

			ans[1] = i; //denotes that there is already something there
			search(2);

			for(int k = 1 ; k <= n; k++){
				board[k][i]--;
			}

			for(int k = 1 ;1-k >= 1 && (i+k) <= n ; k++){
				board[1-k][i+k]--;
			}

			for(int k = 1 ;1+k <= n && (i-k) >= 1 ; k++){
				board[1+k][i-k]--;
			}

			for(int k = 1 ; 1-k >=1 && (i-k) >= 1; k++){
				board[1-k][i-k]--;
			}

			for(int k = 1 ;1+k <= n && (i+k) <= n ; k++){
				board[1+k][i+k]--;
			}
		}
   }

	m = m * 2;

	if(n%2 == 0){
   		fprintf(fout , "%d\n", m);
   		return 0;
	}

	special = true;
	int i = (n/2 + 1);
	for(int k = 1 ; k <= n; k++){
		board[k][i]++;
	}

	for(int k = 1 ; 1-k >=1 && (i-k) >= 1; k++){
		board[1-k][i-k]++;
	}

	for(int k = 1 ;1+k <= n && (i+k) <= n ; k++){
		board[1+k][i+k]++;
	}

	for(int k = 1 ;1-k >=1 && (i+k) <= n ; k++){
		board[1-k][i+k]++;
	}

	for(int k = 1 ;1+k <= n && (i-k) >= 1 ; k++){
		board[1+k][i-k]++;
	}

	ans[1] = i; //denotes that there is already something there
	search(2);

	for(int k = 1 ; k <= n; k++){
		board[k][i]--;
	}

	for(int k = 1 ;1-k >= 1 && (i+k) <= n ; k++){
		board[1-k][i+k]--;
	}

	for(int k = 1 ;1+k <= n && (i-k) >= 1 ; k++){
		board[1+k][i-k]--;
	}

	for(int k = 1 ; 1-k >=1 && (i-k) >= 1; k++){
		board[1-k][i-k]--;
	}

	for(int k = 1 ;1+k <= n && (i+k) <= n ; k++){
		board[1+k][i+k]--;
	}



   fprintf(fout , "%d\n", m);
   return 0;
}