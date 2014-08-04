#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> segment_tree;
vector<int> lazy;
int arr_size;

int query(int * K , int lo , int hi , int cur_lo = 0 , int cur_hi = arr_size - 2 , int node = 0){
	if(lazy[node] != -1) {
		segment_tree[node] = max(segment_tree[node] , lazy[node]);
		if(cur_hi != cur_lo){
			lazy[node*2+1] = max(lazy[node*2+1] , lazy[node]);
			lazy[node*2+2] = max(lazy[node*2+2] , lazy[node]);
		}
		lazy[node] = -1;
	}

	if(cur_lo > hi || cur_hi < lo || cur_lo > cur_hi)
		return -1;

	if(cur_lo >= lo && cur_hi <= hi){
		return segment_tree[node];
	}

	int a = query(K , lo , hi , cur_lo , (cur_lo + cur_hi) /2 , node * 2 + 1);
	int b = query(K , lo , hi , (cur_lo+cur_hi)/2 + 1 , cur_hi , node *2 + 2);
	return max(a,b);
}

void setSegmentTree(int * K , int val , int lo , int hi , int cur_lo = 0, int cur_hi = arr_size -2 , int node = 0){
	if(lazy[node] != -1) {
		segment_tree[node] = max(segment_tree[node] , lazy[node]);
		if(cur_hi != cur_lo){
			lazy[node*2+1] = max(lazy[node*2+1] , lazy[node]);
			lazy[node*2+2] = max(lazy[node*2+2] , lazy[node]);
		}
		lazy[node] = -1;
	}

	if(cur_lo > hi || cur_hi < lo || cur_lo > cur_hi)
		return;

	if(cur_lo >= lo && cur_hi <= hi){
		tree[node] = max(tree[node] , val);
		if(cur_lo != cur_hi){
			lazy[node*2+1] = max(lazy[node*2+1] , val);
			lazy[node*2+2] = max(lazy[node*2+2] , val);
		}
		return;
	}

	setSegmentTree(K , val , lo , hi , cur_lo , (cur_hi + cur_lo)/2 , node *2 + 1);
	setSegmentTree(K , val , lo , hi , (cur_hi + cur_lo)/2 + 1 , cur_hi , node * 2 + 2);
}

void buildSegmentTree(int *K , int cur_lo , int cur_hi , int node){
	if(cur_lo == cur_hi){
		segment_tree[node] = K[cur_hi];
		return;
	}

	buildSegmentTree(K , cur_lo  , (cur_hi + cur_lo) / 2 , node * 2 + 1);
	buildSegmentTree(K , (cur_hi + cur_lo) / 2 + 1 , cur_hi, node * 2 + 2);	

	segment_tree[node] = std::max(segment_tree[node*2+1] , segment_tree[node*2+2]);
}

int GetBestPosition(int N, int C, int R, int *K, int *S, int *E) {
	segment_tree.resize(4 * N , 0);
	lazy.resize(4 * N , -1);
	arr_size = N;

	buildSegmentTree(K , 0 , N-2 , 0);
	
	int best_pos;
	int best_streak = 0;

	vector<int> reference(N);
	
	// O(N^3)
	for(int pos = 0 ; pos < N ; pos++){
		reference[pos] = R;
		for(int i = 0 j = 0 ; i < N -1 ; i++ , j++){
			if(i == pos)
				j++;
			reference[j] = K[i];
		}

		for(int i = 0 ; i < C ; i++){
			int start = S[i];
			int end = E[i];

			int best = -1;
			int best_index = 0;

			for(int j = start ; j <= end ; j++){
				if(reference[j] > best){
					
				}
			}
		}
	}

	return best_streak;
}
