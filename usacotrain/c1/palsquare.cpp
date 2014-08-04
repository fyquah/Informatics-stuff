/*

ID: fy.q1
LANG: C++
TASK: palsquare
*/

# include <iostream>
# include <fstream>
# include <vector>
# include <algorithm>
# include <string>
# include <utility>
# include <sstream>

using namespace std;

int n;

int main()
{
	ifstream fin("palsquare.in");
	fin >> n;
	fin.close();

	ofstream fout("palsquare.out");

	fout << 1 << " " <<  1 << "\n";

	for(int i = 2 ; i <= 300 ; i++)
	{
		long int k = i * i;
		string str;
		string reverse;
		vector <int> list; //this is  in reverse order!

		while(k != 0)
		{
			list.push_back(k%n);
			k =k/n;
		}

		for(int a = 0 ; a < list.size() ; a++)
		{
			if(list[a] < 10) reverse += (char) (list[a] + 48);
			else if (list[a] >= 10) reverse += (char) (list[a] + 55);
		}

		for(int a = reverse.length() - 1 ; a >= 0 ; a--)
			str += reverse[a];

		if(reverse == str) 
		{
			list.clear();

			int p = i;
			string temp;

			while(p != 0)
			{
				list.push_back(p%n);
				p =p/n;
			}

			for(int a = list.size()-1 ; a >=0 ; a--)
			{
				if(list[a] < 10) temp += (char) (list[a] + 48);
				else if (list[a] >= 10) temp += (char) (list[a] + 55);
			}
			fout << temp << " " << str << "\n";			
		}
	}

	fout.close();
}