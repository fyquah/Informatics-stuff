#include <iostream>
#include <algorithm>
using namespace std;

int all[100002];
int N;
int groups[10];

void solve(int index){
	if(index > N)
	{
		return;
	}

	for(int i = 0 ; i )
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i = 1 ; i <= N ; i++) {
		cin >> all[i];
	}

	solve(1);

	return 0;
}