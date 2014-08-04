#include "encoder.h"
#include "encoderlib.h"
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int convertStringToNumber_encode(const string & x){
	return atoi(x.c_str());
}

string convertNumberToString_encode(const int number){
	stringstream ss;
	ss << number;
	return ss.str();
}

string convertToBaseTwo(int x , bool inverted = true){
	string ans = "";
	while(x != 0){
		int rmd = x % 2;
		if(rmd) ans += '1';
		else ans += '0';
		x /= 2;
	}
	if(inverted)
		return ans;
	else{
		string actual = "";
		for(int i = ans.length() ; i >= 0 ; i--)
			actual += ans[i];
		return actual;
	}
}


void encode(int N, int M[])
{
	//vector<int> sent;
	for(int i = 0 ; i < N ;i++){
		string current_number = convertToBaseTwo(M[i]);

		for(int j = 0 ; j < current_number.length() ; j++)
			if(current_number[j] == '1'){
				if(i >= 32){
					send(8 * (i % 32) + j);
					send(8 * (i % 32) + j);
				}
				else
					send(8 * i + j);
				//send(convertStringToNumber_encode(convertNumberToString_encode(i) + convertNumberToString_encode(j)));
				//sent.push_back(convertStringToNumber_encode(convertNumberToString_encode(i) + convertNumberToString_encode(j)));
			}
			()
	}

	// cout << "The sent list is : " << endl;
	// for(int i = 0 ; i < sent.size() ;i++){
	// 	cout << sent[i] << " ";
	// }
	// cout << endl;
}
