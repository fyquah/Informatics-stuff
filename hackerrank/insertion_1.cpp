#include <iostream>

using namespace std;

int main()
{
	int n;
	int x[1001];
	cin >> n;

	for(int i =0 ; i < n ;i++)
	{
		cin >> x[i];
	}

	int y = x[n-1];

	for(int i = n-1 ; i >= 1 ; i--)
	{
		x[i] = x[i-1];
		for(int k = 0 ; k < n ; k++)
		{
			cout << x[k] << " ";
		}
		cout << "\n";
		if(i == 1){
			x[0] = y;
			for(int j = 0 ; j < n ; j++) {
				cout << x[j] << " ";
			}
			cout << "\n";
			break;
		}
		if(y >= x[i-2]){
			x[i-1] = y;
			for(int j = 0 ; j < n ; j++) {
				cout << x[j] << " ";
			}
			cout << "\n";
			break;		
		}
	}
	return 0;
}