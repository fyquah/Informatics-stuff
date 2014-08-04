#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T , N , M , K;
int map[302][302];
int ans[302][302];

int solve(int r1, int r2 , int c1 , int c2) {
	return map[r2][c2] - map[r2][c1-1] - map[r1-1][c2] + map[r-1][c-1];
}

int main()
{
	cin >> T;
	for(int counter = 0; counter < T ; counter++)
	{
		cin >> N >> M >> K;
		memset(map , 0 , sizeof(map));
		memset(ans , 0 , sizeof(map));
		for(int i = 1 ; i <= N ; i++){
			string str;
			cin >> str;
			for(int j = 1 ; j <= M ; j++){
				if(str[j-1] == 'H')
					map[i][j] = map[i-1][j] + map[i][j-1] - map[i-1][j-1] + 1;
				else
					map[i][j] = map[i-1][j] + map[i][j-1] - map[i-1][j-1];
				ans[i][j] = 0;
			}
		}	

		//r and c denotes the maximum amount of rows and columns
		//a and b denotes the number position of the left most point
		for(int r = 1 ; r <= N ; r++) {
			for(int c = 1 ; c <= M ; c++){
				for(int a = 1 ; a <= N - r + 1 ; a++){
					for(int b = 1 ; b <= M - c + 1; b++){
						if(solve(a,a + r -1,b,b+r-1) >= K) ans[r][c]++;
					}
				}
			}
		}

		for(int i = 1 ; i <= N ;i++)
		{
			for(int j = 1 ; j <= M ; j++)
			{
				
			}
		}

		/*
		for(int i = 1 ; i <= N ; i++){
			for(int j = 1 ; j <= M ; j++)
			{
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		*/

	}
	return 0;
}