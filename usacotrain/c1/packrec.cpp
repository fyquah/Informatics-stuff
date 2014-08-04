/*
ID : fy.q1
LANG : C++
TASK : packrec
*/

# include <iostream>
# include <fstream>
# include <algorithm>
# include <utility>
# include <vector>

using namespace std;
pair <int, bool> selected[4];
pair <int,int> rec[5];

int k;
int min;
vector <pair <int, int > > ans;

void det(int l, int w)
{
	if(l * w < min) {
		ans.clear();
		min = length * width;
		if(length > width)	ans.push_back(width , length);
		else ans.push_back(length, width);
	}
	else if (l * w == min)
	{
		if(length > width)	ans.push_back(width , length);
		else ans.push_back(length, width);
	}
}

struct R
{
	int w,l;
	R(int a, int b)
	{
		l = a;
		w = b;
	}	
};

void solve()
{
	R rectangles[4];

	if(selected[0].second) rectangles[0](rec[selected[0].first].first, rec[selected[0].first].second);
	else  rectangles[0] =  a(rec[selected[0].first].second, rec[selected[0].first].first);

	if(selected[1].second)  rectangles[1](rec[selected[1].first].first, rec[selected[1].first].second);
	else R b(rec[selected[1].first].second, rec[selected[1].first].first);

	if(selected[2].second)  rectangles[2](rec[selected[2].first].first, rec[selected[2].first].second);
	else rectangles[2](rec[selected[2].first].second, rec[selected[2].first].first);

	if(selected[3].second) rectangles[3](rec[selected[3].first].first, rec[selected[3].first].second);
	else rectangles[3](rec[selected[3].first].second, rec[selected[3].first].first);

	//form 1
	int length = 0;
	int width = 0;

	width = a.w + b.w + c.w + d.w;
	length = a.l + b.l + c.l + d.l;

	if(a.l > b.l)

	else

	det(length, width);

	//form 3

	length = 0;
	width = 0;

	if(a.w + b.w > d.l) width = a.w + b.w + c.w;
	else width = d.w + c.w;

	det(length, width);
}

bool check(int x)
{
	for(int i = 0 ; i < 4 ; i++)
		if(selected[i].first == x) return false;
	return true;
}

void search()
{
	int i;
	for(i = 0 ; i < 4 ; i++)
		if(selected[i].first == 0) break;
	if(i >= 4){
		solve();
	} 

	for(int j = 1 ; j <= 4 ; j++)
		if(check(j)) {
			selected[i].first = j;
			selected[i].second = true;
			for(int k = 0 ; k < 4 ; k++) cout << selected[k].first << " ";
				cout << endl;
			search();
			selected[i].second = false;
			search();
		}
	selected[i].first = 0;
	return;
}

int main()
{
	ifstream fin("packrec.in");
	for(int i =1 ; i <= 4 ; i++)
	{
		fin >> rec[i].first;
		fin >> rec[i].second;
	}
	fin.close();

	search();

	cout << k << endl;
	return 0;
}