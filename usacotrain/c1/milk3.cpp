/*

ID: fy.q1
LANG: C++
TASK: milk3
*/

# include <iostream>
# include <fstream>
# include <algorithm>
# include <utility>
# include <vector>
# include <string>

using namespace std;

int ma,mb,mc;
bool all[21][21] = {false};

void search(int c, int b)
{
	int a;
	if(all[c][b] == true) return;
	all[c][b] = true;
	a = mc - b - c;
	//because initial amount is actually that
	//c - > b
	if(c + b > mb) search(c + b - mb , mb);
	else search(0 , b  + c);
	//c - > a
	if(c + a  > ma) search(c - (ma - a) ,  b);
	else search(0 , b);
	//b - > c
	if(b  + c  > mc) search(mc , b - (mc  - c));
	else search(c + b , 0);
	//b - > a
	if(b + a > ma) search(c , b - (ma - a));
	else search(c , 0);
	//a - > c
	if(c + a  > mc ) search(mc , b);
	else search( c + a , b);
	//a - > b
	if(b + a > mb) search(c , mb);
	else search(c , a + b);
}



int main()
{
	ifstream fin("milk3.in");
	fin >> ma >> mb >> mc;
	fin.close();
	search(mc,0);

	bool k = false;
	ofstream fout("milk3.out");
	for(int i = 0 ; i  < 21 ; i++)
		for(int j = 0 ; j < 21  ; j++)
		{
			if(all[i][j] && i + j == mc){
				if(k == false) k = true;
				else fout << " ";
				fout << i;
			} 
		}
		fout << "\n";
	fout.close();
	return 0;
}