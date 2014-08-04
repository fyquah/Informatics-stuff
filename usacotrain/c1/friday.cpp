/*
ID: fy.q1
LANG: C++
TASK: friday
*/
# include <iostream>
# include <fstream>
# include <string>
# include <vector>

using namespace std;
int n;
int days[7]; //sunday, monday, teusday...saturday

int main()
{
	ifstream fin("friday.in");
	fin >> n;
	fin.close();
	int x = 0;
	int y = 6; //refers to the current day, sunday = 0, monday = 1....
	//first 13th of 1900 is a saturday, woohooooo
	int year = 1900;

	while(x < n)
	{

		for(int i = 1 ; i <= 12 ; i++)
		{
			days[y]++;
			if(i == 2)
			{
				if(year % 4 == 0 && (year % 100 != 0 || year % 1000 == 0)) //leap year
					y = y + 29;
				else y = y + 28;
			}
			else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
				y = y + 31;
			else
				y = y + 30;
			y = y % 7;
		}	

		x++;
		year++;
	}


	ofstream fout("friday.out");
	fout << days[6] << " ";
	for(int i = 0 ;  i < 5 ; i++)
		fout << days[i] << " ";
	fout << days[5] << "\n"; 
	fout.close();
}
