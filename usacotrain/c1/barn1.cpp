/*

ID: fy.q1
LANG: C++
TASK: barn1
*/

# include <iostream>
# include <fstream>
# include <vector>
# include <algorithm>
# include <string>
# include <utility>
# include <sstream>

using namespace std;

//m is maximum board , s is number of stalls ,  c is number of cows

int m , s , c , clear, ans;

int cows[200];
int x[200]; 

int main()
{
	ifstream fin("barn1.in");
	fin >> m >> s >> c;
	for(int i = 0 ; i < c ;i++)
	{
		int a;
		fin >> a;
		cows[i] = a;
	}
	fin.close();

	sort(cows , cows + c);

	clear = c - m;
	ans = c;

	if(clear <= 0)
		goto end;

	for(int i =1 ; i < c ; i++)
	{
		x[i-1] = cows[i] - cows[i-1] - 1;
	}

	sort(x , x + c - 1);

	for(int i = 0 ; i < c-1 ; i++)
	{
		if(clear <= 0) break;
		ans += x[i];
		clear--;
	}

	end : 
	ofstream fout("barn1.out");
	fout << ans << "\n";
	fout.close();
	return 0;
}