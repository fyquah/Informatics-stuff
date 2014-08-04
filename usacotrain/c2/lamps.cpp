/*
ID: fy.q1
LANG: C++
TASK: lamps
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector <int> on;
vector <int> off;
set <string> ans;
bool status[5];
int d[6][2] = {{0,0},{1,1},{1,2},{2,2},{1,3}};
int N;
int C;

void solve()
{
	bool lamps[110];
	int clicks = 0;
	memset(lamps , true , sizeof(lamps));
	for(int i = 1 ; i<= 4 ;i++)
		if(status[i]){
			++clicks;
			for(int j = d[i][0] ; j <= N ; j += d[i][1])
				lamps[j] = !lamps[j];
		}

	for(int i = 0 ; i < on.size() ; i++)
		if(lamps[on[i]] != true) return;
	for(int i =0 ; i < off.size() ; i++)
		if(lamps[off[i]] != false) return;

	if(C < clicks) return;
	if(C%2 != clicks%2) return;
	string temp = "";
	for(int i = 1; i <= N ; i++)
		temp += ((lamps[i]?1:0) + '0');
	ans.insert(temp);
	return;			
}

void generate(int button) {
	if(button == 5)
		return solve();
	status[button] = true;
	generate(button+1);
	status[button] = false;
	generate(button+1);
}

int main()
{
	freopen("lamps.in" , "r" , stdin);
	freopen("lamps.out" , "w" , stdout);

	scanf("%d %d" , &N , &C);
	int a = 0;
	scanf("%d" , &a);
	while(a != -1){
		on.push_back(a);
		scanf("%d" , &a);
	}
	scanf("%d" , &a);
	while(a != -1){
		off.push_back(a);
		scanf("%d" , &a);
	}
	/*for(int i =0  ; i < on.size() ; i++)
		cout << on[i] << " ";
	cout << endl;
	for(int i = 0 ; i < off.size()  ; i++)
		cout << off[i] << " ";
	cout << endl;*/
	generate(1);

	if(ans.size() == 0)
		printf("IMPOSSIBLE\n");
	else
		for(set<string>::iterator it = ans.begin() ; it != ans.end() ; it++)
			cout << *it << "\n";

	return 0;
}
