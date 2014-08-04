#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int inf = 1 << 30;

int main()
{
	int T;
	cin >> T;
	for(int trial = 0; trial < T ; trial++){
		int N;
		cin >> N;
		int max_1 , max_2;
		max_2 = max_1 = 0;
		for(int i =0 ; i < N ; i++){
			int val;
			cin >> val;
			if(val >= max_2){
				if(val >= max_1){
					max_2 = max_1;
					max_1 = val;
				}
				else
					max_2 = val;
			}
			//cout << max_1 << " " << max_2 << endl;
		}

		cout << max_1 + max_2 << "\n";
	}    
    return 0;
}
