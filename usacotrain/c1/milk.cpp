/*

ID: fy.q1
LANG: C++
TASK: milk
*/

# include <iostream>
# include <fstream>
# include <vector>
# include <algorithm>
# include <string>
# include <utility>
# include <sstream>

using namespace std;

int n, m ,ans;
pair <int, int> farmer[5000];

int main()
{
	ifstream fin("milk.in");
	fin >> n;
	fin >> m;
	for(int i = 0 ; i < m ;i++)
	{
		int a,b;
		fin >> a >> b;
		farmer[i].first = a;
		farmer[i].second = b;
	}
	fin.close();

	sort(farmer , farmer + m);

	for(int i = 0 ; i <m ; i++)
	{
		if(farmer[i].second < n)
		{
			n = n - farmer[i].second;
			ans += farmer[i].first * farmer[i].second;
		}
		else
		{
			ans += farmer[i].first * n;
			break;
		}

	}


	ofstream fout("milk.out");
	fout << ans << "\n";
	fout.close();

	return 0;
}