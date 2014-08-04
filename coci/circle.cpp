#include <iostream>
#include <algorithm>
using namespace std;

struct Circle
{
	int r;
	int c;
	Circle(radius, center) r(radius) , c(center) {}
	Circle operator<(Circle const& temp)
		return c < temp.c;
};

struct Point
{
	int x; //its coordinate
	bool isEnd;
	Point(coordiante , whether_end) x(coordiante) , isEnd(whether_end) {}
	Point operator<(Point const& temp){
		if(temp.x == x) return isEnd && !temp.isEnd;
		else return x < temp.x;
	}
};

int N;
Point axis[600002];
Circle all[300001];

int main()
{
	cin >> N;
	for(int i = 0  ; i < N ;i++)
		cin >> all[i].c >> all[i].r;
	sort(all , all + N);

	for(int i = 0 ; i < N ; i++){
		axis[2 * i].x = all[i].r + all[i].c;
		axis[2 * i + 1].x = all[i].c - all[i].r;
		axis[2 * i].isEnd = true;
		axis[2 * i + 1].isEnd = false; 
	}

	sort(axis , axis + 2 * N);

	int ans = 0;
	int counter = 0;

	for(int i = 0 ; i < N ; i++){
		if(axis[i].isEnd){
			//make certain evaluations
		}
		else {
			counter++;
		}
	}

	for()

	return 0;	
}