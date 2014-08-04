/*

ID: fy.q1
LANG: C++
TASK: crypt1
*/

# include <iostream>
# include <fstream>
# include <vector>
# include <algorithm>
# include <string>
# include <utility>
# include <sstream>

using namespace std;
int k;
int n;
int all[9];

bool check(int a)
{
	for(int i = 10; a != 0 ; i = i * 10)
	{
		int x = (a % i) * 10 / i ;
		cout << x << " ";
		for(int j = 0 ; j < n ;j++)
			if(x == all[j]) goto okay;
		return false;
		okay:
		a -= x * i / 10;
	}
	return true;
}



int main()
{
	ifstream fin("crypt1.in");
	fin >> n ;
	for(int i = 0 ; i < n ; i++)
		fin >> all[i];
	fin.close();

	for(int a = 0 ; a < n ;a++)
		for(int b = 0 ; b < n ; b++)
			for(int c = 0 ; c < n ;c++)
				for(int d =0 ; d < n ;d++)
					for(int e = 0 ; e < n ;e++)
					{
						int x = (all[a] *100 + all[b] * 10 + all[c]) * (all[d]);
						int y = (all[a] *100 + all[b] * 10 + all[c]) * (all[e]);
						if(x > 999 || x < 100 || y < 100 || y > 999 || x * 10 + y > 9999) continue;

						if(check(x) && check(y) && check(x*10 + y)) k++;
						

					}

	ofstream fout("crypt1.out");	
	fout << k << "\n";
	fout.close();

	return 0;
}