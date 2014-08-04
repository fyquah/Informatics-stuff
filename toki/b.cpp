#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <stack>
#include <queue>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

int N , P , Q;
char anto[2010];
char budi[2010];
bool correct[2010][5];
int number[2010];
bool cur[2010];
set <string> ans;
bool same[2010];

int main()
{
	ios_base::sync_with_stdio(false);
	memset(cur , false, sizeof(cur));
	cin >> N >> P >> Q;
	for(int i = 1 ;i <= N ; i++)
		cin >> anto[i];
	for(int i = 1 ;i <= N ; i++){
		cin >> budi[i];
		if(budi[i] == anto[i]) same[i] = true;
	}

	for(int i = 1 ; i <= N ; i++) {
		string temp;
		cin >> temp;
		for(int j =0 ; j < temp.size() ; j++)
			if(temp[j] != '.'){
				correct[i][j] = true;
				number[i]++;
			}
	}
	//impossible to do recursion, sure stack overflow
	for(int i = 1;  i <= N ; i++){
		for(int j = 0 ; j < 5 ; j++) {
			if(correct[i][j] == false) continue;
			
		}
	}

	/*
	//Debug code
	for(int i =1 ; i <= N ; i++){
		for(int j = 0 ; j < 5 ; j++)
			cout << correct[i][j] << " ";
		cout << endl;
	}
	*/




	return 0;
}