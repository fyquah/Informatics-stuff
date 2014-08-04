/*

ID: fy.q1
LANG: C++
TASK: ariprog
*/

# include <iostream>
# include <fstream>
# include <algorithm>
# include <utility>
# include <vector>
# include <string>

using namespace std;

int n; //length of A.P.
int m; // upper boundary of p and q
bool done[125001] = {false};
vector <int> list;
vector <int> diff;

vector <pair<int, int> > ans; //first stores difference, second stores first term

int main()
{
	ifstream fin("ariprog.in");
	fin >> n >> m;
	fin.close();

	//create a vector (list) containing all the Bisquare numbers
	for(int i = 0  ; i <= m ; i++){
		for(int j = i ; j <= m ; j++){
			int a = i * i + j * j;
			if(done[a] == false){
				list.push_back(a);
				done[a] = true;
			}
		}
	}

	sort(list.begin() , list.end());

	cout << list.size() << endl;

	for(int i = 0;i < list.size() ; i++){
		for(int j = i + 1 ; j < list.size(); j++) {

			int a = list[i];	
			int d = list[j] - list[i];
			int valid = true;

			if(d == 0) continue;	
			if(a + (n-1)*d > list[list.size() - 1]) break;

			for(int k = 1 ; k < n ; k++){
				if(done[a + (k)*d] == false) {
					valid = false;
					break;
				}
			}

			if(valid) ans.push_back(make_pair(d, a));
		}	
	}

	sort(ans.begin(), ans.end());

	ofstream fout("ariprog.out");
	if(ans.size() == 0) fout << "NONE" << "\n";
	else
		for(int i =0 ; i < ans.size() ; i++)
			if(i == 0 || (ans[i].first != ans[i-1].first || ans[i].second != ans[i-1].second))
			fout << ans[i].second << " " << ans[i].first << "\n";

	return 0;
}