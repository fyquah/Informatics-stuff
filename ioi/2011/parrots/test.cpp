#include "encoder.h"
#include "encoderlib.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int convertStringToNumber_encode(const string & x){
	return atoi(x.c_str());
}

string convertNumberToString_encode(const int number){
	stringstream ss;
	ss << number;
	return ss.str();
}

string convertToBaseTwo(int x){
	string ans = "";
	while(x != 0){
		int rmd = x % 2;
		if(rmd) ans += '1';
		else ans += '0';
		x /= 2;
	}
	return ans;
}

vector <int> encode(int i , int M)
{
	vector <int> x;
	string current_number = convertToBaseTwo(M);
	for(int j = 0 ; j < current_number.length() ; j++)
		if(current_number[j] == '1')
			x.push_back(convertStringToNumber_encode(convertNumberToString_encode(i) + convertNumberToString_encode(j)));
	return x;
}

string convertNumberToString_decode(const int number){
	stringstream ss;
	ss << number;
	string str = ss.str();
	if(str.length() == 1)
		return ("00" + str);
	else if(str.length() == 2)
		return ("0" + str);
	else
		return str;
}

int main()
{
	int a, b;
	cin >> a >> b;
	vector <int> x = encode(a,b);
	int sum = 0;
	vector <string> super_string;
	for(int i = 0 ; i < x.size() ; i++){
		super_string.push_back(convertNumberToString_decode(x[i]));
		cout << convertNumberToString_decode(x[i]) << endl;
	}
		
	// for(int i = 0 ; i < super_string.size() ; i++){
	// 	sum += (int) pow(2 , convertStringToNumber_encode(super_string[i].substr(2,1)));
	// }

	// cout << sum << endl;
	return 0;
}