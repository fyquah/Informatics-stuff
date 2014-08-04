/*

ID: fy.q1
LANG: C++
TASK: numtri
*/

# include <iostream>
# include <fstream>
# include <algorithm>
# include <utility>
# include <vector>
# include <string>

using namespace std;

int n;
int ans;

int all[1001][1001];
int sum[1001][1001];

//0 means left, 1 means right

int main()
{
	ifstream fin("numtri.in");
	fin >> n;

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < i + 1 ; j++){
			int x;
			fin >> x;
			all[i][j] = x;
		}
	}
	fin.close();

	sum[0][0] = all[0][0];

	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j < i + 1 ; j++){
			if(j == 0 || sum[i-1][j] > sum[i-1][j-1]) sum[i][j] = sum[i-1][j] + all[i][j];
			else sum[i][j] = sum[i-1][j-1] + all[i][j];
		}
	}
	
	for(int i = 0 ; i < n ; i++)
		if(sum[n - 1][i] > ans) ans = sum[n-1][i];

	ofstream fout("numtri.out");
	fout << ans << "\n";
	fout.close();
}