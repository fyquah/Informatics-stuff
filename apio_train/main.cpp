#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;

struct Trader
{
	int start;
	int end;
	int index;
	Trader(int a, int b , int c) : start(a) , end(b) , index(c) {}
};

int N, M;
int a[300030]; //all the starting prices for the traders
bool active[300030]; //all the active trades
vector <pii> starts;
vector <pii> ends;

int main()
{
	ios_base::sync_with_stdio(false);
	freopen("trading.in" , "r" , stdin);
	freopen("trading.out" , "w" , stdout);
	cin >> N >> M; //N vilages, M Traders

	for(int i = 1 ; i<= N ; i++){
		int a , b , c;
		cin >> a >> b >> c;
		starts.push_back(make_pair(a,i));
		ends.push_back(make_pair(b,i));
		a[i] = c;
	}

	sort(starts.begin(),starts.end());
	sort(ends.begin(),ends.end());

	int i ,j;
	i = j = 0;
	int cur = 0;
	int prev_pos = 1;
	priority_queue<pii> value;

	while(i < start.size() || j < end.size()) {
		bool is_end;
		if( j!= end.size() && (i == start.size() || (end[j].first < start[i].first))){
			is_end = true;
			active[ends[j].second] = false;
		}
		else {
			is_end = false;
			active[starts[i].second] = true;
		}

		if(is_end){
			
			j++;
		}
		else {

			i++;
		}



	}


	for(int i = 1 ; i <= N ; i++){
		if(i > 1) cout << " ";
		cout << get(i) - get(i-1);
	}

	cout << "\n";

	return 0;
}