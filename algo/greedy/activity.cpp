#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Activity
{
public:
	int begin;
	int end;
	string name;
	Activity(int b , int e , string n){
		begin = b;
		end = e;
		name = n;
	}
	bool operator>=(const Activity &another) const {
		return (start >= another.end)
	}
};

int main()
{

	vector <Activity> all;
	vector <Activity> selected;
	selected.push_back(Activity(0 , 0 , "Wake up"));
	
	for(int i = 0 ; i < all.size() ; i++)
		if(all[i] >= selected[selected.size()-1])
			selected.push_back(all[i]);

	return 0;
}