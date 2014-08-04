/*
ID: fy.q1
LANG: C++
TASK: castle
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
using namespace std;


int M , N; // M is the width, N is the height
int all[60][60];
bool visited[60][60];
int floor_plan[60][60]; //contains index on which room does the current floor belong to
int all_rooms[2510];

int cur_size = 0;

int n_rooms =0;
int largest_single =0;

void visit(int r , int c , int x)
{
	if(visited[r][c]) return;
	visited[r][c] = true;
	floor_plan[r][c] = x;
	cur_size++;
	if((all[r][c] | 14) == 14) visit(r,c-1,x); //1110 west
	if((all[r][c] | 13) == 13) visit(r-1,c,x); //1101 north
	if((all[r][c] | 11) == 11) visit(r,c+1,x); //1011 east
	if((all[r][c] | 7) == 7)   visit(r+1,c,x); //0111 south
}

int main()
{
	ios_base::sync_with_stdio(false);
	freopen("castle.in" ,"r" , stdin);
	freopen("castle.out" ,"w" , stdout);


	cin >> M >> N;

	for(int i = 1 ; i <= N ; i++)
		for(int j = 1 ; j <= M ; ++j)
			cin >> all[i][j];
		
	for(int i = 1 ;i <= N ;i++)
		for(int j = 1 ;j <= M ;j++)
			if(!visited[i][j]){
				visit(i,j,n_rooms + 1);
				n_rooms++;
				all_rooms[n_rooms] = cur_size;
				largest_single = max(largest_single , cur_size);
				cur_size = 0;
			}

	//try 'smashing every north and east door and see what happens'

	int largest_dual =0;
	int ar = 0;
	int aw = 0;
	char c;

	/*
	for(int i = 1 ; i<= N ;i++)
	{
		for(int j = 1; j <= M ;j++)
			cout << floor_plan[i][j] << " ";
		cout << endl;
	}

	for(int i = 1  ;i <= n_rooms ; i++){
		cout << all_rooms[i] << endl;
	}
	*/

	for(int j = 1 ;j <= M  ;j++){
		for(int i = N ; i>= 1 ; i--){
			if(i > 1 && floor_plan[i][j] != floor_plan[i-1][j] && all_rooms[floor_plan[i][j]] +all_rooms[floor_plan[i-1][j]] > largest_dual)
			{
				largest_dual = all_rooms[floor_plan[i][j]] +all_rooms[floor_plan[i-1][j]];
				ar = i;
				aw = j;
				c = 'N';
			}

			if(j < M && floor_plan[i][j] != floor_plan[i][j+1] && all_rooms[floor_plan[i][j]] + all_rooms[floor_plan[i][j+1]] > largest_dual)
			{
				largest_dual = all_rooms[floor_plan[i][j]] + all_rooms[floor_plan[i][j+1]];
				ar =i;
				aw =j;
				c = 'E';
			}
		}
	}

	cout << n_rooms << "\n" << largest_single << "\n";
	cout << largest_dual << "\n";
	cout << ar << " " << aw << " " << c << "\n";
	return 0;
}