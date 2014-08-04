// Longest palindrome by removing some characters
// using dynamic programming
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string str;

int len(int begin , int end){
	if(begin == end)
		return 1;
	else if(begin + 1 == end && str[begin] == str[end])
		return 2;
	
	if(str[begin] == str[end]) return 2 + len(begin + 1 , end -1);
	else return max(len(begin + 1 , end) , len(begin , end -1));
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> str;
	cout << "Longest palindrom by removing some character is " << len(0 , str.length() - 1) << endl;
	return 0;
}
