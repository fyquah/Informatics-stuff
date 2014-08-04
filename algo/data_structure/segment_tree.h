#include <vector>
#include <algorithm>

const int inf = 1 << 30;

class SegmentTree
{
public:
	SegmentTree(int n);
	SegmentTree(int n , const int * arr);
	void increment(int lo , int hi , int value);
	void decrement(int lo , int hi , int value);
	void increment(int pos , int value);
	void decrement(int pos , int value);
	int query(int lo , int hi);
private:
	void build_tree(int node , int i , int j);
	void update_tree(int node , int i , int j , int lo , int hi , int value);
	int query_tree(int node , int i , int j , int lo , int hi);
	void lazy_propogate(int node , bool end_pos);
	int size;
	std::vector<int> tree;
	std::vector<int> container;
	std::vector<int> lazy;
};	

SegmentTree::SegmentTree(int n){
	tree.resize(4 * n , 0);
	lazy.resize(4 * n , 0);
	container.resize(n , 0);
	size = n;
}

SegmentTree::SegmentTree(int n , const int * arr){
	size = n;
	tree.resize(4 * n , 0);
	lazy.resize(4 * n , 0);
	container.resize(n , 0);
	for(int i =0 ; i < n ; i++)
		container[i] = arr[i];
	build_tree(0 , 0 , n-1);
}

void SegmentTree::increment(int lo , int hi , int value){
	update_tree(0 , 0 , size-1 , lo , hi , value);
}

void SegmentTree::decrement(int lo , int hi , int value){
	update_tree(0 , 0 , size-1 , lo , hi , -value);
}

void SegmentTree::increment(int pos , int value){
	update_tree(0 , 0 , size-1 , pos , pos , value);
}

void SegmentTree::decrement(int pos , int value){
	update_tree(0 , 0 , size-1 , pos , pos , value);
}

int SegmentTree::query(int lo , int hi){
	return query_tree(0 , 0 , size-1 , lo , hi);
}

void SegmentTree::build_tree(int node , int i , int j){
	if(i > j)
		return;
	if(i == j){
		tree[node] = container[i];
		return;
	}
	build_tree(node*2+1 , i , (i+j)/2);
	build_tree(node*2+2 , (i+j)/2 + 1 , j);
	tree[node] = std::max(tree[node*2+1] , tree[node*2+2]);
}

void SegmentTree::update_tree(int node , int i , int j , int lo , int hi , int value){
	lazy_propogate(node , i == j);

	if(j < lo || i > hi || i > j)
		return;

	else if (i >= lo && j <= hi){
		tree[node] += value;
		if(i != j){
			lazy[node*2+1] += value;
			lazy[node*2+2] += value;
		}
		return;
	}

	update_tree(node*2+1 , i , (i+j)/2 , lo , hi , value);
	update_tree(node*2+2 , (i+j)/2 +1 , j , lo , hi , value);

	tree[node] = std::max(tree[node*2+1] , tree[node*2+2]);
}

int SegmentTree::query_tree(int node ,int i , int j , int lo , int hi){
	lazy_propogate(node , i == j);
	if(i > hi || j < lo || i > j)
		return -inf;
	else if(i >= lo && j <= hi)
		return tree[node];	
	else
		return std::max(query_tree(node*2+1 , i , (i+j)/2 , lo , hi) , query_tree(node*2+2 , (i+j)/2 + 1 , j , lo , hi));
}

void SegmentTree::lazy_propogate(int node , bool end_pos){
	if(lazy[node] != 0){
		tree[node] += lazy[node];
		if(end_pos == false){
			lazy[node*2+1] += lazy[node];
			lazy[node*2+2] += lazy[node];
		}
		lazy[node] = 0;
	}
}