/*
ID: fy.q1
LANG: C++
TASK: namenum
*/
# include <iostream>
# include <fstream>
# include <string>
# include <vector>
# include <algorithm>

using namespace std;

string code;
int n;
char current[12];
vector<string> answer;
string dic[4617];

void evaluate()
{
	//use binary search to look for the answer
	string str = "";
	for(int i =0  ; i < n ;i++)
		str += current[i];
	int lo = 0;
	int high = 4616;
	int mid;

	while(lo < high)
	{
		mid = (lo + high)/2;
		if(str > dic[mid]) lo = mid + 1;
		else if (str < dic[mid]) high = mid;
		else if (str == dic[mid])
		{
			answer.push_back(str);
			return;
		}
	}

	if(str == dic[mid]) answer.push_back(str);
	return;
}

void solve(int a)
{
	if(a >= n)
	{
		evaluate();
		return;
	}
	for(int i = 0 ; i < 3 ; i++)
	{
		if(code[a] == '2') {
			int z = 65 + i;
			current[a] = (char)z;
		}
		else if(code[a] == '3') {
			int z = 68 + i;
			current[a] = (char)z;
		}
		else if(code[a] == '4') {
			int z = 71 + i;
			current[a] = (char)z;
		}
		else if(code[a] == '5') {
			int z = 74 + i;
			current[a] = (char)z;
		}
		else if(code[a] == '6') {
			int z = 77 + i;
			current[a] = (char)z;
		}
		else if(code[a] == '7') {
			int z = 80 + i + 1;
			if(i == 0) z--;
			current[a] = (char)z;
		}
		else if(code[a] == '8') {
			int z = 84 + i;
			current[a] = (char)z;
		}
		else if(code[a] == '9') {
			int z = 87 + i;
			current[a] = (char)z;
		}

		solve(a + 1);
	}
	return;
}

int main()
{
	ifstream fin("namenum.in");
	fin >> code;
	fin.close();

	n = code.length();

	ifstream dictionary("dict.txt");
	for(int i = 0 ; i < 4617 ; i++)
	{
		string abc;
		dictionary >> abc;
		dic[i] = abc;
	}
	dictionary.close();
	ofstream fout("namenum.out");
	solve(0);


	if(answer.size() == 0)
	{
		fout << "NONE" << "\n";
		fout.close();
		return 0;
	}
	for(int i =0  ; i < answer.size() ; i++)
		fout << answer[i] << "\n";
	fout.close();
	return 0;
}