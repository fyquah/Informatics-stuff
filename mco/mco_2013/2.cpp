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
		int N , K;
		vector < pair <int , int > > all;

		cin >> N >> K;
		
		for(int i = 0 ; i < N ; i++){
			int a, b;
			cin >> a >> b;
			all.push_back(make_pair(a , b));
		}

		sort(all.begin() , all.end());

		int counter = 0;

		for(int i = 0 ; i < all.size() ; i++){
			counter += all[i].second;
			if(counter >= K){
				cout << all[i].first << "\n";
				goto end;
			} 
		}

		cout << all[all.size() -1].first << "\n";

		end:;
	}

	return 0;
}