#include "decoder.h"
#include "decoderlib.h"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cmath>
using namespace std;

vector <vector <int> > tidy;
vector <string> super_string_array;

int convertStringToNumber_decode(const string & str){
	return atoi(str.c_str());
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

void cat(const int L , const int * X){
	for(int i = 0 ; i < L ; i++)
		super_string_array.push_back(convertNumberToString_decode(X[i]));

	for(int i = 0 ; i < L ; i++){
		string current_string = super_string_array[i];
		int position = convertStringToNumber_decode(current_string.substr(0,2));
		tidy[position].push_back(convertStringToNumber_decode(current_string.substr(2,1)));
	}
}

vector <vector<int> > group;

inline void assemble(const int bit_position){
	int position = bit_position / 8;
	int rmd = bit_position % 8;
	group[position].push_back(rmd);
}

void decode(int N , int L , int X[]){
	group.resize(N);

	sort(X , X + L);

	vector<int> positions;

	for(int i = 0 ; i < L ; i++){
		if(i + 2 < L && X[i] == X[i+1] && X[i+1] == X[i+2]){
			positions.push_back(X[i]);
			positions.push_back(X[i] + 256);
			i += 2;
		}
		else if(i + 1 < L && X[i] == X[i+1]){
			positions.push_back(X[i] + 256);
			i++;
		}
		else {
			positions.push_back(X[i]);
		}
	}

	for(int i = 0 ; i < positions.size() ; i++){
		assemble(positions[i]);
	}

	for(int i = 0 ; i < group.size() ; i++){
		int sum = 0;
		for(int j = 0 ; j < group[i].size() ; j++)
			sum += (int) pow(2 , group[i][j]);
		output(sum);
	}

	// damn global variables -.-
	group.clear();
}
/*
void decode(int N, int L, int X[])
{
	tidy.resize(N + 3);
	cat(L , X);

	
	for(int i = 0 ; i < N ; i++){
		cout << i << "-> " << endl;
		for(int j = 0 ; j < tidy[i].size() ; j++){
			cout << tidy[i][j] << " ";
		}
		cout << endl;
	}


	for(int i = 0 ; i < N ; i++){
		int sum = 0;
		for(int j = 0 ; j < tidy[i].size() ; j++)
			sum += (int) pow(2 , tidy[i][j]);
		output(sum);
	}
	tidy.clear();
	super_string_array.clear();
	return;
}
*/
