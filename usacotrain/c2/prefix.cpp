/*
ID: fy.q1
LANG: C++
TASK: prefix
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector <string> col;
string str = "";
bool mark[200010];

int np;
int ans = 0;
int len = 0;


int main()
{
	freopen("prefix.in" , "r" , stdin);
	freopen("prefix.out" , "w" , stdout);

	string temp;
	cin >> temp;
	while(temp != ".") {
		col.push_back(temp);
		cin >> temp;
	}
	cin.ignore();
	getline(cin , temp);
	while(temp != ""){
		str += temp;
		getline(cin , temp);
	}
	len = str.length();
	np = col.size();

	for(int i = 0 ; i < np ; i++) {
		int x = col[i].length();
		if(str.substr(0,x) == col[i]) mark[x-1] = true;
	}

	for(int i = 0 ; i < len ; i++)
		if(mark[i])
			for(int j = 0 ; j < np ; j++){
				int x = col[j].length();
				if(str.substr(i+1,x) == col[j]) mark[i+x] = true;
			}



	for(int i = len-1 ; i>= 0 ; i--)
		if(mark[i]){
			printf("%d\n" , (i+1));
			return 0;
		}
	printf("0\n");
}
