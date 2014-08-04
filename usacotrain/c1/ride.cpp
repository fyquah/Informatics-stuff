/*

ID: fy.q1
LANG: C++
TASK: ride
*/

# include <iostream>
# include <fstream>
# include <vector>
# include <algorithm>
# include <string>

using namespace std;

string x; // group
string y; //human

long long int a = 1;
long long int b = 1;

int main()
{
	ifstream fin("ride.in");
	fin >> x >> y;
	fin.close();

	for(int i = 0 ; i < x.length() ; i++)
	{
		int k = (int) x[i] - 64;
		a = a * k;
	}

	for(int i = 0 ; i < y.length() ; i++)
	{
		int z = (int) y[i] - 64;
		b = b * z;
	}

	ofstream fout("ride.out");

	if(a % 47 == b % 47) fout << "GO";
	else fout << "STAY";
	fout << "\n";

	fout.close();
}