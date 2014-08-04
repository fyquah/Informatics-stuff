# include <iostream>
# include <string>

using namespace std;

int main()
{
	long long int n;
	cin >> n;

	int* x = new int[n];
	string* str = new string[n];

	for(long long int i = 0 ; i < n/2 ; i++)
	{
		cin >> x[i];
		cin >> str[i];
		str[i] = "-";
	}

	for(long long int i = n/2; i < n ;i++)
	{
		cin >> x[i];
		cin >> str[i];
	}

	int largest_number = 0;

	for(long long int i = 0 ; i < n ; i++)
	{
		if(x[i] > largest_number) largest_number = x[i];
	}

	for (long long int i = 0  ; i <= largest_number ; i++)
	{
		for(long long int j = 0 ; j < n ; j++)
		{
			if(x[j] == i) cout << str[j] << " ";
		}
	}
	cout << "\n";

	delete[] x;
	delete[] str;

	return 0;
}