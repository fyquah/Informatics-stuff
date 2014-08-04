#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int T;

int main()
{
	cin >> T;
	for(int trial = 0 ; trial < T ; trial++){
		int N , Q;
		vector <string> dic;
		vector <string> query;
		cin >> N >> Q;

		for(int i =0 ; i < N ;i++){
			string temp;
			cin >> temp;
			dic.push_back(temp);
		}

		for(int i = 0;  i< Q ; i++){
			string temp;
			cin >> temp;
			query.push_back(temp);
		}

		sort(dic.begin() , dic.end());

		for(int i =0 ;i < Q ; i++){
			int pos = lower_bound(dic.begin() , dic.end() , query[i]) - dic.begin();
			int counter = 0;
			for(int j = pos ; j < dic.size() ; j++){
				if(dic[j].substr(0 , query[i].length()) == query[i]) counter++;
				else break;
			}
			cout << counter << "\n";
		}

	}

	return 0;
}