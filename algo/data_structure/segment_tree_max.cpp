//MAX IN RANGE ALGORITHM, O(log 2N)
#include <cstdio>
#include <algorithm>

int arr[] = {1,6,3,83,5,1,845,24,1,2,6,8,3,4454,2,1};
int tree[100];
int n;

int search(int i, int j, int cur_i , int cur_j, int node){
	if(i > cur_j || j < cur_i) return 0;
	if(cur_i >= i && cur_j <= j) return tree[node];
	return std::max(search(i ,j ,cur_i,(cur_i+cur_j)/2,node*2+1) , search(i, j, (cur_i+cur_j)/2 + 1, cur_j , node*2+2));

}

int construct(int lo, int hi, int node)
{
	if(lo == hi)
		return tree[node] = arr[lo];
	else
		return tree[node] = std::max(construct(lo, (lo+hi)/2, node*2+1), construct((lo+hi)/2 + 1, hi, node*2+2));
}

int main()
{
	n = sizeof(arr) / sizeof(arr[0]);
	construct(0,n-1,0);
	printf("The highest bewwen 1 and 6 inclusive is %d",search(1,5,0,n-1,0));
}