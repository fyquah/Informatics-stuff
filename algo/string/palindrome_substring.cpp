#include <string>
#include <cstring>
#include <iostream>
using namespace std;

string str;
int dp[1000][1000];

int len(int begin , int end){
	if(begin == end)
		return 1;
	else if(begin + 1 == end && str[begin] == str[end])
		return 2;
	
	if(dp[begin][end] != -1)
		return dp[begin][end];

	//consider all possiblities:
	int a = len(begin + 1 , end -1);
	int b = len(begin , end -1);
	int c = len(begin + 1 , end);
	if(str[begin] == str[end] && (begin+end) % 2 == 0 && a == (end - begin - 1) ) 
		a+= 2;
	return dp[begin][end] = max(a,max(c,b));

}

int main()
{
	ios_base::sync_with_stdio(false);
	memset(dp , -1 , sizeof dp);
	cin >> str;
	cout << len(0 , str.length() -1) << endl;
	return 0;
}
