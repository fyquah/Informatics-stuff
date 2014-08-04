/*

ID: fy.q1
LANG: C++
TASK: calfflac
*/

# include <iostream>
# include <vector>
# include <string>
# include <fstream>
# include <algorithm>
# include <vector>

using namespace std;

pair <int , int> longest;
int l = 0;
int n;
pair <char , int> data[20000];
string all;

void find(int left, int right)
{
	if(data[left].first != data[right].first) return;
	while(left >= 0 && right <= n - 1)
	{
		if(data[left-1].first == data[right+1].first) {
			left--;
			right++;
		}
		else break;
	}
	int y = right - left + 1;
	if(y > l)
	{
		l = y;
		longest.first = data[left].second;
		longest.second = data[right].second;
		return;
	}
}


int main()
{
	ifstream fin("calfflac.in");
	for(int i = 0 ; 1 < 2 ; i++)
	{
		string line;
		if(getline(fin, line))
		{
			all+= line;
		}
		else break;
		all +="\n";
	}
	fin.close();


	for(int i = 0 ; i < all.length() ; i++)
	{
		if((int) all[i] >= 65 && (int) all[i] <= 122)
		{
			if((int) all[i] <= 90)
			{
				data[n].first = all[i];
				data[n].second = i;
				n++;
			}
			else if ((int) all[i] >= 97)
			{
				int x = all[i];
				data[n].first = (char) (x - 32);
				data[n].second = i;
				n++;
			}
		}
	}

	n++;

	for(int i =1  ; i < n ; i++)
	{
		find(i - 1 , i+ 1);
		find(i - 1 , i);
	}

	ofstream fout("calfflac.out");
	fout << l << "\n";

	for(int i = longest.first ; i <= longest.second ; i++)
	{
		fout << all[i];
	}

	fout << "\n";
	fout.close();
	return 0;
}