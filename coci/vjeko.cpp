#include <iostream>
#include <string>

using namespace std;

int N;
int second_half_index;

string original;
string all[101];
string first_half;
string second_half;

int main()
{
	cin >> N >> original;
	for(int i =0 ;i < N ;i++){
		cin >> all[i];
	}
	//find the index of the first half
	//find the index of the second half
	for(int i =0 ; i < original.length() ;i++)
		if(original[i] == '*'){
			second_half_index = i + 1;
			first_half = original.substr(0,i);
			second_half = original.substr(i+1 , original.length()-i-1);
		}
	
	for(int i =0 ;i < N ; i++){
		if(all[i].length() < original.length() -1){
			cout << "NE" << "\n";
			continue;
		}

		if(all[i].substr(0,first_half.length()) == first_half && second_half == all[i].substr(all[i].length() - second_half.length() , second_half.length()))
			cout << "DA" << "\n";
		else
			cout << "NE" << "\n";
	}

	return 0;
}