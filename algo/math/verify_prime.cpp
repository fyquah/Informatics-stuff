#include <bitset>
#include <vector>
#include <cstdio>
typedef long long ll;

using namespace std;

ll sieve_size;
bitset<10000010> bs;
vector<int> prime;

void sieve(ll upper_bound){
	sieve_size = upper_bound + 1;
	bs.reset();
	bs.flip();
	bs.set(0,false);
	bs.set(1,false);

	for(ll i = 2 ; i <= sieve_size ; i++){

		if(bs.test(i)){
			for(ll j = i * i ; j <= sieve_size ; j += i){
				bs.set(j , false);
			}
			prime.push_back(i);
		}
	}
}

bool isPrime(ll x){
	if(x <= sieve_size) return bs.test(x);
	else {
		for(int i = 0 ; i < prime.size() ; i++)
			if(x % prime[i] == 0)
				return false;
		return true;
	}
}

int main()
{
	sieve(10000000);
	printf("%d" , isPrime(100));
	return 0;
}
