#include <cstdio>

int T;
char map[50][50];

int main()
{
	freopen("test.in" , "r" , stdin);
	freopen("test.out" , "w" , stdout);
	scanf("%d" , &T);
	
	for(int trial =0 ; trial < T ; trial++){

		int R , C , M;
		scanf("%d %d %d" , &R , &C , &M);
		int n = R * C - M;
		bool can = false;

		if(n == 1){
			for(int i= 0 ; i < R ; i++)
				for(int j = 0 ; j < C ; j++){
					if(i ==0 && j == 0) map[i][j] = 'c';
					else map[i][j] = '*';
				}
			can = true;
			goto end;
		}

		if(r == 1 || c == 1){
			for(int i = 0; i < R ; i++)
				for(int j = 0 ; j < C ; ++j){
					if(n != 0){
						if(i == 0 && j == 0) map[i][j] = 'c';
						else map[i][j] = '.';
						n--;					
					}
					else
						map[i][j] = '*';
				}
			can = true;
			goto end;
		}

		if(R == 2){
			if(C == 2) goto end;
			if(n % 2 ==1 || n < 4) goto end;
			for(int i = 0; i < C ; i++)
				for(int j = 0 ; j < R ; ++j){
					if(n != 0){
						if(i == 0 && j == 0) map[j][i] = 'c';
						else map[j][i] = '.';
						n--;					
					}
					else
						map[j][i] = '*';
				}
			can = true;
			goto end;

		}

		if(C == 2){
			if(R == 2) goto end;
			if(n % 2 ==1 || n < 4) goto end;
			for(int i = 0; i < R ; i++)
				for(int j = 0 ; j < C ; ++j){
					if(n != 0){
						if(i == 0 && j == 0) map[i][j] = 'c';
						else map[i][j] = '.';
						n--;					
					}
					else
						map[i][j] = '*';
				}
			can = true;
			goto end;
			
		}

		if(n % 2 == 0 && n < 4) goto end;
		if(n % 2 == 1 && n < 9) goto end;
			
		if(n >= 3 * C){
			if(n % C == 1){ //there is a last mine in the last row
				int point_r = n /C;
				for(int i = 0; i < R ; i++)
					for(int j = 0 ; j < C ; ++j){
						if(n != 0){
							if(i == 0 && j == 0) map[i][j] = 'c';
							else map[i][j] = '.';
							n--;					
						}
						else
							map[i][j] = '*';
					}
				map[point_r][1] = '.';
				map[point_r - 1][C-1] = '*';
				can = true;
				goto end;
			}
			else{
				for(int i = 0; i < R ; i++)
					for(int j = 0 ; j < C ; ++j){
						if(n != 0){
							if(i == 0 && j == 0) map[i][j] = 'c';
							else map[i][j] = '.';
							n--;					
						}
						else
							map[i][j] = '*';
				}
				can = true;
				goto end;
			}
		}

		else{
			if(n %2 ==0){
				int temp = n/2;

				for(int i =0 ; i < R ; i++)
					for(int j = 0 ; j < C ; j++) {
						if(i == 0 && j ==0) map[i][j] = 'c';
						else if(i <= 1 && j < temp) map[i][j] = '.';
						else map[i][j] =  '*';
					}
			}
			// non even cases
			else{
				int temp = (n-3) /2;
				for(int i =0 ; i < R ; i++)
					for(int j = 0 ; j < C ; j++){
						if(i == 0 && j == 0) map[i][j] = 'c';
						else if(i <= 1 && j < temp) map[i][j] = '.';
						else if(i == 2 && j < 3) map[i][j] = '.';
						else map[i][j] = '*'; 
					}
			}
			can = true; 
			goto end;

		}



		/*
		if(M % R == 0){
			if(n == R) goto end;
			for(int i = 0 ; i < C ; i++)
				for(int j= 0 ; j < C ; j++) {
					if(n != 0){
						if(i == 0 && j == 0) map[i][j] = 'c';
						else map[i][j] = '.';
						n--;					
					}
					else
						map[i][j] = '*';
				}
			can = true;
			goto end;
		}


		if(M %C == 0)
		{
			if(n == C) goto end;
			if(n % 2 ==1 || n < 4) goto end;
			for(int i = 0; i < R ; i++)
				for(int j = 0 ; j < C ; ++j){
					if(n != 0){
						if(i == 0 && j == 0) map[i][j] = 'c';
						else map[i][j] = '.';
						n--;					
					}
					else
						map[i][j] = '*';
				}
			can = true;
			goto end;
		}
		*/
		//other conditions



		end:
		cout << "Case #" << trial + 1 << ":\n";
		if(can){
			for(int i = 0 ; i < R ; i++){
				for(int j = 0 ; j < C ; j++)
					cout << map[i][j];
				cout << "\n";
			}

		}
		else
			cout << "Impossible\n";

	}

	return 0;
}