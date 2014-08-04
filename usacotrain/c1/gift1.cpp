/*
ID: fy.q1
LANG: C++
TASK: gift1
*/
# include <iostream>
# include <fstream>
# include <string>
# include <vector>

using namespace std;
int n;
string name_list[10];
int donate_list[10][10];
int money[10];
int new_money[10];
int share[10];

//function returns the index of the intended person
int lookup(string person)
{
	for(int i = 0  ; i < n ; i++)
	{
		if(person == name_list[i]) return i;
	}
	return -1;
}


int main()
{
	ifstream fin("gift1.in");
	fin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		fin >> name_list[i];
	}

	for(int i = 0 ; i < n ; i++)
	{
		string temp;
		fin >> temp;
		int a = lookup(temp);

		fin >> money[a];
		fin >> share[a];

		for(int k = 0 ; k < share[a] ; k++)
		{
			string test;
			fin >> test;
			int b = lookup(test);
			donate_list[a][k] = b;
		}
	}
	fin.close();
	for(int i = 0 ; i < n ; i++)
	{
		if(money[i] == 0 || share[i] == 0) continue;
		new_money[i] += (money[i] % share[i]);
		int c = money[i] - money[i] % share[i];
		int y = c / share[i];
		for(int j = 0 ; j < share[i] ; j++)
		{
			new_money[donate_list[i][j]] += y;
		}
	}

	ofstream fout("gift1.out");
	for(int i = 0 ; i < n ; i++)
	{
		fout << name_list[i] << " " << new_money[i] - money[i] << "\n";
	}
	fout.close();
}