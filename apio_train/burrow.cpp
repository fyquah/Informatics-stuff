#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <stack>
using namespace std;

int N , M , K;
int mat[1050][1050];
vector <int> all_price;
int area;
int ans;
int asst[1050][1050];

int find_max()
{
	stack<int> index;
	stack<int> height;
	int largest = 0;
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= M  ; j++){
	      	if(height.empty() || height.top() < asst[i][j]){
	        	height.push(asst[i][j]);
	        	index.push(j);
	      	}
			else if(height.top() > asst[i][j]){
				int last_index = 1;
				while(!height.empty() && asst[i][j] < height.top()){
					int a = height.top();
					last_index = index.top();
					largest = max(largest , (j-last_index)*(a));
					height.pop();
					index.pop();
				}
				height.push(asst[i][j]);
				index.push(last_index);
			}
		}
		while(!height.empty()){
			int c = index.top();
			int b = height.top();
			int A = (M+1-c) * b;
			largest = max(largest , A);
			index.pop();
			height.pop();
		}
	}
	return largest;
}

bool span(int price)
{
	memset(asst, 0 , sizeof(asst));
	for(int j = 1 ; j <= M ; j++)
		for(int i = 1 ; i <= N ; i++)
			asst[i][j] = (mat[i][j]>=price?(asst[i-1][j]+1):0);
	int x = find_max();
	if(x >= K){
		area = x;
		return true;
	}
	else return false;
}

void search()
{
	int lo = 1;
	int hi = 1000000000;
	int mid;
	while(lo != hi){
		mid = lo + (hi-lo+1)/2;
		if(span(mid)) lo = mid;
		else hi = mid -1;		
	}
	ans = lo;
}

int main()
{
	ios_base::sync_with_stdio(false);
	freopen("burrow.in" , "r" , stdin);
	freopen("burrow.out" , "w" , stdout);
	cin >> N >> M >> K;
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1; j <= M ; j++){
			cin >> mat[i][j];
			all_price.push_back(mat[i][j]);
		}
	}
	sort(all_price.begin() , all_price.end());
	search();	
	cout << ans << " " << area << "\n";
	return 0;
}