#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int T;

int main()
{
	cin >> T;
	for(int trial = 0 ; trial < T ; trial++){
		int N , M;
		string str;
		cin >> N >> M;
		cin >> str;

		for(int i =0 ; i < M ; i++){
			int type;
			cin >> type;
			if(type ==1) {
				int pos;
				 char c;
				cin >> pos >> c;
				str[pos-1] = c;
			}
			else if (type == 2) {
				char c;
				cin >> c;
				str += c;
			}
		}

		cout << str << "\n";

	}

	return 0;
}