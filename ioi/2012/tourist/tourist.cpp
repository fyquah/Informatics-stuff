#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

// int main()
// {
// 	long long N , K;
// 	priority_queue<long long , vector<long long> , std::greater<long long> > pq;

// 	long long all[1000000];
// 	scanf("%lld %lld" , &N , &K);
// 	for(int i = 0 ; i < N ; i++)
// 		scanf("%lld" , all+i);

// 	if(K == 0){
// 		cout << 0 << "\n";
// 		return 0;
// 	}
// 	else if(K == 1){
// 		cout << all[0] << "\n";
// 		return 0;
// 	}
// 	else if(K == 2){
// 		cout << max(all[0] , all[1]) << "\n";
// 		return 0;
// 	}

// 	long long max_happy = 0;
// 	long long happy = 0

// 	pq.push(all[0]);
// 	happy = max_happy = all[0];
// 	for(int i = 1 ; i < N ; i++){
// 		if(K - i < pq.size()){
// 			pq.push(all[i]);
// 			happy += all[i];
// 			max_happy += all[i];
// 		}
// 		else if(K - i == 0){
// 			break;
// 		}
// 		else {
// 			pq.push(all[i]);
// 			happy += all[i];
// 			while(pq.size() > K - i){
// 				happy -= pq.top();
// 				pq.pop();
// 			}
// 		}
// 	}
// }



int main()
{
	ios::sync_with_stdio(false);
	int N;
	long long K;
	priority_queue<long long , vector<long long> , std::greater<long long> > pq; // we wnat to pop / top the small stuff out first

	long long all[1000000];
	scanf("%d %lld" , &N  , &K);
	for(int i = 0 ; i < N ; i++)
		scanf("%lld" , all + i);
	
	if(K == 0){
		cout << "0\n";
		return 0;
	}
	else if(K == 1) {
		cout << all[0] << "\n";
		return 0;
	}
	else if(K == 2){
		cout << max(all[1] , all[0]) << "\n";
		return 0;
	}

	long long max_happy = 0;
	long long happy = 0;
	// Standard solving procedure
	int i;
	pq.push(all[0]);
	happy += all[0];
	max_happy += all[0];

	for(i = 1 ; i < N; i++) {
		if(K - i > pq.size()){
			pq.push(all[i]);
			happy += all[i];
			max_happy += all[i];
		}
		else if(K - i == 0)
			break;
		else {
			pq.push(all[i]);
			happy += all[i];
			while(K - i < pq.size()){
				happy -= pq.top();
				pq.pop();
			}
			max_happy = max(happy , max_happy);
		}
	}

	cout << max_happy << "\n";

	// if(K % 2) // Odd K cases
	// 	for( ; i < N ; i++){
	// 		happy -= pq.top();
	// 		pq.pop();
	// 		// cout << pq.top() << " ";
	// 		if(pq.top() < all[i]) {
	// 			happy -= pq.top();
	// 			happy += all[i];
	// 			pq.pop();
	// 			pq.push(all[i]);
	// 			max_happy = max(happy , max_happy);
	// 		}
	// 	}
	// else
	// 	for( ; i < N && i <= K; i++){
	// 		if(pq.top() < all[i]) {
	// 			happy -= pq.top();
	// 			happy += all[i];
	// 			pq.pop();
	// 			pq.push(all[i]);
	// 			max_happy = max(happy , max_happy);
	// 		}
	// 		happy -= pq.top();
	// 		pq.pop();
	// 	}
	return 0;
}

	// if(K >= N-1){
	// 	// int overnights = K - N + 1;
	// 	// sort(all , all + N , greater<int>());
	// 	// int ans = 0;
	// 	// for(int i = 0 ; i < overnights && i < N ; i++)
	// 	// 	ans += all[i];
	// 	// printf("%d\n" , ans);
	// }
	// else{

	// }