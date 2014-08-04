/*
ID: fy.q1
LANG: C++
TASK: zerosum
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
# include <set>
using namespace std;

vector <string> ans;
short status[10];
int N;
int counter;

void dfs(int cur){
	// if(cur > N){
	// 	int fig = 0;
	// 	int cum = 0;
	// 	int deg = 0;

	// 	string temp = "";
		
	// 	for(int i = N ; i > 1 ; i--) {
	// 		cum += (i) * pow(10 , deg);
	// 		if(status[i] == 1) //+ sign
	// 			fig += cum;
	// 		else if (status[i] == 2) // - sign
	// 			fig -= cum;
	// 		else { //empty bar
	// 			deg++;
	// 		}
	// 		if(status[i] != 3){
	// 			deg = 0;
	// 			cum = 0;
	// 		}
	// 	}

	// 	if(cum != 0)
	// 		fig += cum + pow(10 , deg);
	// 	else 
	// 		fig += 1;

	// 	if(fig == 0) {
	// 		string str = "1";
	// 		for(int i = 1 ; i < N ; i++){
	// 			if(status[i] == 1)
	// 				str.push_back('+');
	// 			else if (status[i] == 2)
	// 				str.push_back('-');
	// 			else 
	// 				str.push_back(' ');
	// 			str.push_back(i+1+'0');
	// 		}
	// 		ans.push_back(str);
	// 	}

	// 	return;
	// }

	if(cur > N) {
		int deg = 1;
		int cum = 0;
		int fig = 0;

		for(int i = N ; i > 1 ; i--){
			cum += i * deg;
			if(status[i] == 3){
				deg = deg * 10;
			}
			else if (status[i] == 2){ // +
				fig += cum;
				deg = 1;
				cum = 0;
			}
			else if (status[i] == 1){ // -
				fig -= cum;
				deg = 1;
				cum = 0;
			}
		}

		fig += deg + cum;
		if(fig == 0){
			string str = "1";
			for(int i = 2 ; i <= N ; i++){
				if(status[i] == 1)
					str.push_back('-');
				else if (status[i] == 2)
					str.push_back('+');
				else 
					str.push_back(' ');
				str.push_back(i+'0');
			}
			ans.push_back(str);
		}
		return;
	}

	for(int i = 1 ; i <= 3 ; i++){
		status[cur] = i;
		dfs(cur+1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	freopen("zerosum.in" , "r" , stdin);
	freopen("zerosum.out" , "w" , stdout);

	cin >> N;

	dfs(2);

	sort(ans.begin() , ans.end());

	for(vector<string>::iterator it = ans.begin() ; it < ans.end() ; it++)
		cout << *it << "\n";

	return 0;
}