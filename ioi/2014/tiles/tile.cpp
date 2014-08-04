#include "tile.h"
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

int ciritcal_x;
int critical_y;
int width;
vector< vector<int> > ans;

void generateRectangle(const int x1 , const int y1 , const int x2 , const int y2 , const int x3 , const int y3){
	vector<int> temp;
	temp.resize(6);
	temp[0] = x1;
	temp[1] = y1;
	temp[2] = x2;
	temp[3] = y2;
	temp[4] = x3;
	temp[5] = y3;
	ans.push_back(temp);
	return;
}

void drawRectangles(const int x1 , const int y1 , const int x2 , const int y2 , const int dark_x , const int dark_y){

	if(x2 - x1 + 1 == 2){
		if(dark_x == x1 && dark_y == y1)
			generateRectangle(x1 , y2 , x2 , y1 , x2 , y2);
		else if (dark_x == x2 && dark_y == y1)
			generateRectangle(x1 , y1 , x1 , y2, x2 , y2);
		else if (dark_x == x1 && dark_y == y2)
			generateRectangle(x1 , y1 , x2 , y1 , x2 , y2);
		else if (dark_x == x2 && dark_y == y2)
			generateRectangle(x1 , y1 , x1 , y2 , x2 , y1);
		return;
	}

	if(dark_x >= x1 && dark_x <= (x1 + x2)/2 && dark_y >= y1 && dark_y <= (y1+y2)/2){
		// X O
		// O O
		drawRectangles(x1 , y1 , (x1+x2)/2 , (y1+y2)/2, dark_x , dark_y);
		drawRectangles(x1 , (y1+y2)/2 + 1 , (x1+x2)/2 , y2 , (x1+x2)/2 , (y1+y2)/2 + 1);
		drawRectangles((x1+x2)/2 + 1 , y1 , x2 , (y1+y2)/2 , (x1+x2)/2 + 1 , (y1+y2)/2);
		drawRectangles((x1+x2)/2 + 1 , (y1+y2)/2 + 1 , x2 , y2 , (x1+x2)/2 + 1 , (y1+y2)/2 + 1);
		generateRectangle((x1+x2)/2 , (y1+y2)/2 + 1 , (x1+x2)/2 + 1 , (y1+y2)/2 , (x1+x2)/2 + 1 , (y1+y2)/2 + 1);

	}
	else if(dark_x >= (x1+x2)/2 + 1 && dark_x <= x2 && dark_y >= y1 && dark_y <= (y1+y2)/2){
		// O X
		// O O
		drawRectangles(x1 , y1 , (x1+x2)/2 , (y1+y2)/2, (x1+x2)/2 , (y1+y2)/2);
		drawRectangles(x1 , (y1+y2)/2 + 1 , (x1+x2)/2 , y2 , (x1+x2)/2 , (y1+y2)/2 + 1);
		drawRectangles((x1+x2)/2 + 1 , y1 , x2 , (y1+y2)/2 , dark_x , dark_y);
		drawRectangles((x1+x2)/2 + 1 , (y1+y2)/2 + 1 , x2 , y2 , (x1+x2)/2 + 1 , (y1+y2)/2 + 1);
		generateRectangle((x1+x2)/2 , (y1+y2)/2 , (x1+x2)/2 , (y1+y2)/2 + 1 , (x1+x2)/2 + 1 , (y1+y2)/2 + 1);
	}
	else if(dark_x >= x1 && dark_x <= (x1 + x2)/2 && dark_y >= (y1 + y2)/2 + 1 && dark_y <= y2){
		// O O 
		// X O
		drawRectangles(x1 , y1 , (x1+x2)/2 , (y1+y2)/2, (x1+x2)/2 , (y1+y2)/2);
		drawRectangles(x1 , (y1+y2)/2 + 1 , (x1+x2)/2 , y2 , dark_x , dark_y);
		drawRectangles((x1+x2)/2 + 1 , y1 , x2 , (y1+y2)/2 , (x1+x2)/2 + 1 , (y1+y2)/2);
		drawRectangles((x1+x2)/2 + 1 , (y1+y2)/2 + 1 , x2 , y2 , (x1+x2)/2 + 1 , (y1+y2)/2 + 1);
		generateRectangle((x1+x2)/2 , (y1+y2)/2 , (x1+x2)/2 + 1 , (y1+y2)/2 , (x1+x2)/2 + 1 , (y1+y2)/2 + 1);
	}
	else if(dark_x >= (x1+x2)/2 + 1 && dark_x <= x2 && dark_y >= (y1 + y2)/2 + 1 && dark_y <= y2){
		// O O 
		// O X
		drawRectangles(x1 , y1 , (x1+x2)/2 , (y1+y2)/2, (x1+x2)/2 , (y1+y2)/2);
		drawRectangles(x1 , (y1+y2)/2 + 1 , (x1+x2)/2 , y2 , (x1+x2)/2 , (y1+y2)/2 + 1);
		drawRectangles((x1+x2)/2 + 1 , y1 , x2 , (y1+y2)/2 , (x1+x2)/2 + 1 , (y1+y2)/2);
		drawRectangles((x1+x2)/2 + 1 , (y1+y2)/2 + 1 , x2 , y2 , dark_x , dark_y);
		generateRectangle((x1+x2)/2 , (y1+y2)/2 , (x1+x2)/2 , (y1+y2)/2 + 1 , (x1+x2)/2 + 1 , (y1+y2)/2);
	}
	return;
}

void placeTile(int n, int x, int y, int pos[][6])
{
	width = (int) pow(2, n);
	drawRectangles(0 , 0 , width -1 , width - 1 , x , y);

	for(int i =0 ; i < ans.size() ; i++)
		for(int j = 0 ; j < 6 ; j++)
			pos[i][j] = ans[i][j];

	return;
}
