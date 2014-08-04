/*
ID: fy.q1
LANG: C++
TASK: dualpal
*/
# include <iostream>
# include <vector>
# include <algorithm>
# include <fstream>
# include <utility>
# include <string>

using namespace std;

int n;
int s;

int counter = 0;

int main()
{
	ifstream fin("dualpal.in");
	fin >> n >> s;
	fin.close();

	ofstream fout("dualpal.out");
	for(int i = s + 1 ; counter < n  ; i++)
	{
		bool completed = false;
		for(int j = 2 ; j <= 10 ; j++)
		{
			long int k = i;
			string str;
			string reverse;
			vector <int> list; //this is  in reverse order!

			while(k != 0)
			{
				list.push_back(k%j);
				k =k/j;
			}

			for(int a = 0 ; a < list.size() ; a++)
				reverse += (char) (list[a] + 48);
			for(int a = reverse.length() - 1 ; a >= 0 ; a--)
				str += reverse[a];



			if(str == reverse && completed)
			{
				fout << i << "\n";
				counter++;
				break;	
			} 
			else if (str == reverse && !completed) completed = true;
		}
	}
	fout.close();
	return 0;
}