#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 29;
vector< vector<int> > tree_max;
vector< vector<int> > tree_min;
int N , M;
int mat[510][510];

void merge_tree(const int node_x){
	int left = node_x * 2 + 1;
	int right = node_x * 2 + 2;
	
	for(int i = 0 ; i < tree_max[node_x].size() ; i++){
		tree_max[node_x][i] = max(tree_max[left][i] , tree_max[right][i]);
		tree_min[node_x][i] = min(tree_min[left][i] , tree_min[right][i]);
	}
	
}

void buildTree_y(const int node_x , const int cor_x, const int cur_lo = 0 , const int cur_hi = M - 1 , const int node = 0){
	if(cur_lo == cur_hi){
		tree_max[node_x][node] = mat[cor_x][cur_lo];
		tree_min[node_x][node] = mat[cor_x][cur_lo];
		//cout << "AT " << cor_x << " , " << cur_lo << " is " << tree_max[node_x][node] << " ";
		//cout << endl;
		return;
	}
	
	int mid = (cur_lo + cur_hi)/2;
	buildTree_y(node_x , cor_x , cur_lo , mid , node * 2 + 1);
	buildTree_y(node_x , cor_x ,  mid + 1 , cur_hi , node * 2 + 2);
	tree_max[node_x][node] = max(tree_max[node_x][node * 2 + 1] , tree_max[node_x][node * 2 + 2]);
	tree_min[node_x][node] = min(tree_min[node_x][node * 2 + 1] , tree_min[node_x][node * 2 + 2]);
}

void buildTree(const int cur_lo = 0 , const int cur_hi = N - 1 , const int node = 0){
	//cout << "cur_lo" << " = " << cur_lo << " and " << "cur_hi = " << cur_hi << endl;
	if(cur_lo == cur_hi){
		buildTree_y(node , cur_lo);
		return;
	}
	//
	int mid = (cur_lo + cur_hi)/2;
	buildTree(cur_lo , mid , node * 2 + 1);
	buildTree(mid+1 , cur_hi , node * 2 + 2);
	merge_tree(node);
}

int queryTreeMin_y(const int node_x , const int y_lo , const int y_hi , const int cur_lo = 0 , const int cur_hi = M - 1 , const int node = 0){
	if(cur_lo > y_hi || cur_hi < y_lo || y_lo > y_hi)
		return inf;
	
	if(cur_lo >= y_lo && cur_hi <= y_hi)
		return tree_min[node_x][node];
	
	int mid = (cur_lo + cur_hi)/2;
	int a = queryTreeMin_y(node_x , y_lo , y_hi , cur_lo , mid , node*2+1);
	int b = queryTreeMin_y(node_x , y_lo , y_hi , mid + 1 , cur_hi , node*2+2);
	return min(a,b);
}

int queryTreeMin(const int x_lo , const int x_hi , const int y_lo , const int y_hi , const int cur_lo = 0 , const int cur_hi = N - 1 , const int node = 0){
	if(x_lo > cur_hi || x_hi < cur_lo || x_lo > x_hi)
		return inf;
		
	if(cur_lo >= x_lo && cur_hi <= x_hi)
		return queryTreeMin_y(node , y_lo , y_hi);
	
	int mid = (cur_lo + cur_hi)/2;
	int a = queryTreeMin(x_lo , x_hi , y_lo , y_hi , cur_lo , mid , node *2 + 1);
	int b = queryTreeMin(x_lo , x_hi , y_lo , y_hi , mid + 1 , cur_hi , node * 2 + 2);
	
	return min(a,b);
}

int queryTree_y(const int node_x , const int y_lo , const int y_hi , const int cur_lo = 0 , const int cur_hi = M - 1 , const int node = 0){
	if(cur_lo > y_hi || cur_hi < y_lo || y_lo > y_hi)
		return -1;
	
	if(cur_lo >= y_lo && cur_hi <= y_hi)
		return tree_max[node_x][node];
	
	int mid = (cur_lo + cur_hi)/2;
	int a = queryTree_y(node_x , y_lo , y_hi , cur_lo , mid , node*2+1);
	int b = queryTree_y(node_x , y_lo , y_hi , mid + 1 , cur_hi , node*2+2);
	return max(a,b);
}

int queryTree(const int x_lo , const int x_hi , const int y_lo , const int y_hi , const int cur_lo = 0 , const int cur_hi = N - 1 , const int node = 0){
	if(x_lo > cur_hi || x_hi < cur_lo || x_lo > x_hi)
		return -1;
		
	if(cur_lo >= x_lo && cur_hi <= x_hi)
		return queryTree_y(node , y_lo , y_hi);
	
	int mid = (cur_lo + cur_hi)/2;
	int a = queryTree(x_lo , x_hi , y_lo , y_hi , cur_lo , mid , node *2 + 1);
	int b = queryTree(x_lo , x_hi , y_lo , y_hi , mid + 1 , cur_hi , node * 2 + 2);
	
	return max(a,b);
}

void mergeUpdate(const int node_x , const int y_lo , const int y_hi , const int cur_lo = 0 , const int cur_hi = M - 1 , const int node = 0){
	if(cur_lo > y_hi || cur_hi < y_lo || cur_lo > cur_hi)
		return;
	
	if(cur_lo >= y_lo && cur_hi <= y_hi){
		tree_max[node_x][node] = max(tree_max[node_x*2+1][node] , tree_max[node_x*2+2][node]);
		return;
	}
	int mid = (cur_lo + cur_hi)/2;
	mergeUpdate(node_x , y_lo , y_hi , cur_lo , mid , node *2 + 1);
	mergeUpdate(node_x , y_lo , y_hi , mid + 1 , cur_hi , node * 2 + 2);
	tree_max[node_x][node] = max(tree_max[node_x*2+1][node] , tree_max[node_x*2+2][node]);
}

void updateTree_y(const int node_x , const int y_lo , const int y_hi , const int value , const int cur_lo = 0 , const int cur_hi = M - 1 , const int node = 0){
	if(cur_lo > y_hi || cur_hi < y_lo || cur_lo > cur_hi)
		return;
	
	if(cur_lo >= y_lo && cur_hi <= y_hi){
		tree_max[node_x][node] = value;
		tree_min[node_x][node] = value;
		return;
	}
	
	int mid = (cur_lo + cur_hi)/2;
	updateTree_y(node_x , y_lo , y_hi , value , cur_lo , mid , node * 2 + 1);
	updateTree_y(node_x , y_lo , y_hi , value , mid + 1  , cur_hi , node * 2 + 2);
	tree_max[node_x][node] = max(tree_max[node_x][node*2+1] , tree_max[node_x][node*2+2]);
	tree_min[node_x][node] = min(tree_min[node_x][node*2+1] , tree_min[node_x][node*2+2]);
}	

void updateTree(const int x_lo , const int x_hi , const int y_lo , const int y_hi , const int value , const int cur_lo = 0 , const int cur_hi = N - 1, const int node = 0){
	if(x_lo > cur_hi || x_hi < cur_lo || x_lo > x_hi)
		return;
	
	if(cur_lo >= x_lo && cur_hi <= x_hi){
		updateTree_y(node , y_lo , y_hi , value);
		return;
	}
	
	int mid = (cur_lo + cur_hi)/2;
	updateTree(x_lo , x_hi , y_lo , y_hi , value , cur_lo , mid , node * 2 + 1);
	updateTree(x_lo , x_hi , y_lo , y_hi , value , mid + 1 , cur_hi , node * 2 + 2);
	merge_tree(node);
}

int main(){
	cin >> N >> M;
	tree_max.resize(4 * N);
	tree_min.resize(4 * N);
	for(int i = 0 ; i < tree_max.size() ; i++){
		tree_max[i].resize(4 * M);
		tree_min[i].resize(4 * M);	
	}
		
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			cin >> mat[i][j];
		}
	}
	
	buildTree();
	
	int q;
	cin >> q;
	
	for(int i = 0 ; i < q ; i++){
		char c;
		cin >> c;
		if(c == 'q'){
			int r1,c1,r2,c2;
			cin >> r1 >> c1 >> r2 >> c2;
			cout << queryTree(r1-1,r2-1,c1-1,c2-1) << " " << queryTreeMin(r1-1,r2-1,c1-1,c2-1) << endl;
		}
		else {
			int a,b,c;
			cin >> a >> b >> c;
			updateTree(a-1,a-1,b-1,b-1,c);
		}
	}
	
	return 0;
}
