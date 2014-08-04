#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N , K;
long long arr[1000010];
long long rsq[1000010];
long long dynamic[1000010];
long long tree[1000010];

void set(long long index, long long value){
	while(index <= N){
		tree[index] += value;
		index += index & (-index);
	}
}

long long get(long long index){
	long long sum = 0;
	while(index > 0){
		sum += tree[index];
		index -= index & (-index);
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for(int i = 1 ; i <= N ; i++){
		cin >> arr[i];
		rsq[i] += (arr[i] + rsq[i-1]);
		dynamic[i] = rsq[i];
	}

	sort(dynamic , dynamic + N + 1);
	int p = unique(dynamic , dynamic + N + 1) - dynamic;

	for(int i = 0 ; i <= N ; i++){
		
	}



	int new_width = std::distance(rsq)

	return 0;
}