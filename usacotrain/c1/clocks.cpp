/*

ID: fy.q1
LANG: C++
TASK: clocks
*/

# include <iostream>
# include <fstream>
# include <algorithm>
# include <utility>
# include <vector>
# include <string>

using namespace std;

int start[10];
int sol[10];
int selected[10];
string answer = "";

bool confirm()
{
	for(int i = 0 ; i  <= 9 ; i++)
		if(sol[i] % 12 != 0) return false;
	return true;
}

void solve(int a){
	if(a == 0) {
		sol[1] = start[1] + 3 * (selected[1] + selected[2] + selected[4]); //A
		sol[2] = start[2] + 3 * (selected[1] + selected[2] + selected[3] + selected[5]); //B
		sol[3] = start[3] + 3 * (selected[2] + selected[3] + selected[6]); //C
		sol[4] = start[4] + 3 * (selected[1] + selected[4] + selected[5] + selected[7]); //D
		sol[5] = start[5] + 3 * (selected[1] + selected[3] + selected[5] + selected[7] + selected[9]); //E
		sol[6] = start[6] + 3 * (selected[3] + selected[5] + selected[6] + selected[9]); //F
		sol[7] = start[7] + 3* (selected[4] + selected[7] + selected[8]); //G
		sol[8] = start[8] + 3 * (selected[5] + selected[7] + selected[8] + selected[9]); //h
		sol[9] = start[9] + 3 * (selected[6] + selected[8] + selected[9]); //I

		if(confirm()) {
			string str = "";
			for(int i = 1 ; i <= 9 ; i++) {
				if(selected[i] == 0) continue;
				for(int j = 0 ; j < selected[i] ; j++)
					str += i + 48;
			}
			if(answer == "" || (str.length() < answer.length() && str < answer)) answer = str;
		}
		return;
	}	

	for(int i = 0 ; i < 4 ; i++){
		selected[a] = i;
		solve(a - 1);
	}
}

int main()
{
	ifstream fin("clocks.in");
	for(int i =1 ; i <= 9 ; i++)
		fin >> start[i];
	fin.close();
	solve(9);

	ofstream fout("clocks.out");
	for(int i = 0 ; i < answer.length() ; i++){
		fout << answer[i];
		if(i < answer.length() - 1) fout << " ";
	}

	fout << "\n";

	return 0;
}