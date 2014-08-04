#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define ARR_SIZE 10
using namespace std;

const int inf = 1 << 30;

int tree[ARR_SIZE * 4];
int lazy[ARR_SIZE + 1];
int arr[ARR_SIZE] = {10, 2, 47, 3, 7, 9, 1, 98, 21, 37};

void update_lazy(const int node , const int cur_lo , const int cur_hi){
	if(lazy[node]){
		if(cur_hi != cur_lo){
			lazy[node*2+1] += lazy[node];
			lazy[node*2+2] += lazy[node];
		}
		tree[node] += lazy[node];
		lazy[node] = 0;
	}
}

int query(const int & lo , const int & hi , const int cur_lo = 0 , const int cur_hi = ARR_SIZE - 1, const int node = 0){
	update_lazy(node , cur_lo , cur_hi);

	if(cur_lo < 0 || hi > ARR_SIZE || cur_lo > hi || cur_hi < lo)
		return inf;

	if(cur_lo >= lo && cur_hi <= hi)
		return tree[node];
	else 
		return min(query(lo , hi , cur_lo , (cur_lo + cur_hi) /2 , node*2+1) , query(lo , hi , (cur_lo + cur_hi) /2 + 1 , cur_hi , node*2+2));
}

void increment_entry(const int & lo , const int & hi , const int & val , const int cur_lo = 0 , const int cur_hi = ARR_SIZE - 1, const int node = 0){

	update_lazy(node , cur_lo , cur_hi);

    if(cur_lo < 0 || hi > ARR_SIZE || cur_lo > hi || cur_hi < lo || cur_lo > cur_hi)
        return;

    if(cur_lo >= lo && cur_hi <= hi){
        tree[node] += val;
        if(cur_lo != cur_hi){
        	lazy[node*2+1] += val;
        	lazy[node*2+2] += val;
        	cout << "LAZY!!!" << endl;
        }
        return;
    }

    else {
    	increment_entry(lo , hi , val , cur_lo , (cur_lo + cur_hi)/2 , node*2 + 1);
    	increment_entry(lo , hi , val , (cur_lo + cur_hi)/2 + 1 , cur_hi , node*2 + 2);
    	tree[node] = min(tree[node*2+1] , tree[node*2+2]);
    }
}

void build_tree(const int cur_lo = 0 , const int cur_hi = ARR_SIZE - 1, const int node = 0){
    if(cur_lo < 0 || cur_hi >= ARR_SIZE)
        return;

    if(cur_lo == cur_hi){
    	//cout << cur_lo << " : " << arr[cur_lo] << endl;
        tree[node] = arr[cur_lo];
        return;
    }

    else{
        build_tree(cur_lo , (cur_lo+cur_hi)/2 , node * 2 + 1);
        build_tree((cur_lo+cur_hi)/2 + 1 , cur_hi ,node * 2 + 2);
        tree[node] = min(tree[node*2+1] , tree[node * 2 + 2]);
    }
}

int main()
{
    memset(tree , 0 , sizeof tree);
    memset(lazy , 0 , sizeof lazy);
    build_tree();
    
    cout << query(0,9) << endl;
    increment_entry(6,9,100);
    cout << query(0,9) << endl;
    increment_entry(1,1,100);
    cout << query(1,9) << endl;
    for(int i = 0 ; i < ARR_SIZE ; i++)
    	cout << query(i,i) << " ";
    cout << endl;	
    return 0;
}
