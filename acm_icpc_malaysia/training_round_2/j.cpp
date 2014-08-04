#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[1010];
int tree[10000];
int N;

int queryTree(int lo , int hi , int cur_lo = 0 , int cur_hi = N - 1 , int node = 0){
	if(cur_lo > hi || cur_hi < lo || cur_lo > cur_hi)
		return -1;

	if(cur_lo >= lo && cur_hi <= hi){
		return tree[node];
	}

	int a = queryTree(lo , hi , cur_lo , (cur_lo + cur_hi) /2 , node*2+1);
	int b = queryTree(lo , hi , (cur_lo + cur_hi)/2 + 1 , cur_hi , node*2+2);

	if(a == -1) return b;
	if(b == -1) return a;
	if(arr[a] > arr[b]) return a;
	else return b;
}

void buildTree(int cur_lo = 0 , int cur_hi = N-1 , int node = 0){
	if(cur_lo == cur_hi){
		tree[node] = cur_hi;
		return;
	}

	buildTree(cur_lo , (cur_hi + cur_lo)/2 , node*2+1);
	buildTree((cur_hi + cur_lo)/2 + 1 , cur_hi , node*2+2);

	if(arr[tree[node*2+1]] > arr[tree[node*2+2]])
		tree[node] = tree[node*2+1];
	else
		tree[node] = tree[node*2+2];
}

int evaluate(int lo = 0 , int hi = N - 1){
	//cout << lo << " " << hi << endl;
	if(lo < 0 || lo > N || hi < 0 || hi > N)
		return 0;
	// if(hi > -1) cout << hi << ' ' << lo << endl;
	if(lo == hi)
		return 0;

	int max_pos = queryTree(lo , hi);

	if(max_pos == lo)
		return evaluate(max_pos+1 , hi) + arr[max_pos];
	else if(max_pos == hi)
		return evaluate(lo , max_pos -1) + arr[max_pos];
	else
		return evaluate(lo , max_pos - 1) + evaluate(max_pos + 1 , hi) + 2 * arr[max_pos];
}

int main()
{
	ios::sync_with_stdio(false);
	int number_of_cases;
	cin >> number_of_cases;
	for(int trial = 1 ; trial <= number_of_cases ; trial++){
		cin >> N;
		// if(N <= 1000) continue;
		// else throw -1;
		//memset(arr , -1 , sizeof arr);
		//memset(tree , -1 , sizeof tree);
		for(int i = 0 ; i < N ; i++)
			cin >> arr[i];
		buildTree();
		//cout << queryTree(1,3) << endl;
		//return 0;
		cout << "Case #" << trial << ": " << evaluate() << "\n";
	}


	return 0;
}
