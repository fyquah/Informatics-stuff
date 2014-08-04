#include <bits/stdc++.h>
using namespace std;

int N;
vector <vector<int> > tree;

void update(int x , const int y , const int value){
	int y1;
	while(x <= N){
		y1 = y;
		while(y1 <= N){
			tree[x][y1] += value;
			y1 += y1 & (-y1);
		}
		x += x & (-x);
	}
}

int query(int x , const int y){
	int sum = 0;
	int y1 = y;
	while(x >= 1){
		y1 = y;
		while(y1 >= 1){
			sum += tree[x][y1];
			y1 -= y1 & (-y1);
		}
		x -= x & (-x);
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N;
	tree.resize(N + 5 , vector<int>());
	for(int i = 0 ;i < tree.size() ; i++)
		tree[i].resize(N + 2 , 0);
		
	cout << "The array is 1-indexed" << endl;
	while(true){
		char c;
		cin >> c;
		if(c == 'x') break;
		else if(c == 'u'){
			int x , y, value;
			cin >> x >> y >> value;
			update(x ,y , value);
		}
		else if(c == 'q'){
			int x,y ;
			cin >> x >> y;
			cout << query(x , y) << endl;
		}
	}

	return 0;
}
