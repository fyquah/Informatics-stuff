#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int inf = 1 << 30;

int main()
{
	int T;
	cin >> T;
	for(int trial = 1; trial <= T ; trial++){
		int a,b,c;
		cin >> a >> b >> c;
		if(c >= a && c >= b){
			if(a * a + b * b == c * c)
				cout << "Case #" << trial << ": YES\n";
			else	
				cout << "Case #" << trial << ": NO\n";
		}
		else if(b >= a && b >= c){
			if(a * a + c * c == b * b)
				cout << "Case #" << trial << ": YES\n";
			else	
				cout << "Case #" << trial << ": NO\n";
		}
		else{
			if(c * c + b * b == a * a)
				cout << "Case #" << trial << ": YES\n";
			else	
				cout << "Case #" << trial << ": NO\n";
		
		}
	}    
    return 0;
}
