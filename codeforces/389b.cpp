# include <iostream>
# include <vector>
# include <utility>
# include <fstream>
# include <algorithm>

using namespace std;

int n;
int field[10][10];

//the field will have the following numbers
// 0 - there is no hash tag there
// 1 - there is an hash tag there and is single and avilable
// 2 - there is a has tag there, but is not available

bool check_bottom(int i , int j)
{
	if(i < n -2 && j < n-1 && field[i+1][j-1] == 1 && field[i+1][j] == 1 && field[i+1][j+1] == 1 && field[i+2][j] == 1)
	{
		field[i+1][j-1] = field[i+1][j] = field[i+1][j+1] = field[i+2][j] = 2;
		return true;
	}
	else return false;
}

int main()
{
	cin >> n;
	for(int i = 0 ; i < n ;i++)
	{
		string abc;
		cin >> abc;
		for(int j = 0 ; j <  abc.length() ; j++)
			if(abc[j] == '#') field[i][j] = 1;
	}

	for(int i = 0 ; i < n ;i++)
		for(int j = 0 ; j < n ;j++)
		{
			if(field[i][j] == 1)
				if(!check_bottom(i,j))
				{
					cout << "NO" << "\n";
					return 0;
				}
		}
	cout << "YES" << "\n";
	return 0;
}

// in making QAD, make sure to inculude something to allow people to try stuff