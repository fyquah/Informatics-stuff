/*
ID: fy.q1
LANG: C++
TASK: beads
*/
# include <iostream>
# include <fstream>
# include <string>
# include <vector>

using namespace std;
int n;
int x = 1;
int y;
string str , superstr;
int highest;

int solve(char start , char end , int a) // find the last occuring character k before differing
{
	int i;
	for(i  = a + 1 ; i < 2 * n - 1 ; i++)
		if (superstr[i] == end)
			break;
	y = i;
	for(; i < 2 * n - 1 ; i++)
		if(superstr[i] == start)
			break;
	return i;
}

int main()
{
	ifstream fin("beads.in");
	fin >> n;
	fin >> str;
	fin.close();	
	//check front and back first, before proceeding to others

	superstr = str + str;

	for(int i = 0 ; i < 2 * n - 1 ; i++)
	{
		if(superstr[i] == 'b') {
			x = solve('b','r', i);
			if(x - i > highest) highest = x - i;
			x = 0;
		}
		else if (superstr[i] == 'r'){
			x = solve('r','b', i);
			if(x - i > highest) highest = x - i;
			x = 0;
		}

		else if (superstr[i] == 'w'){
			x = solve('r' , 'b' , i);
			int z= solve('b' , 'r' , i);
			if(z - i > highest) highest  = z-i;
			if(x - i > highest) highest = x - i;
			y = 0;
			x = 0;
		}
	}

	if(highest > n || highest == 0) highest = n;

	ofstream fout("beads.out");
	fout << highest << "\n";
	fout.close();
}