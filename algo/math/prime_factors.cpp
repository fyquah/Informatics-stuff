#include <bitset>
#include <vector>
#include <cstdio>
#include <algorithm>
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

vector<ll> primeFactors(ll N)
{
	vector<ll> factors;
	int prime_factor_index = 0;
	int prime_factor = prime[prime_factor_index];
	while(N != 1 && (prime_factor * prime_factor <= N)){
		while(N % prime_factor == 0){
			N /= prime_factor;
			factors.push_back(prime_factor);
		}
		prime_factor = prime[++prime_factor_index];
	}
	if(N != 1) factors.push_back(N);
	return factors;
}

int main()
{
	sieve(10000000);
	printf("%d" , isPrime(113));
	vector<ll> factors = primeFactors(100);
	vector<ll>::iterator it = unique(factors.begin() , factors.end());
	factors.resize(std::distance(factors.begin() , it));
	for(int i = 0 ;i < factors.size() ; i++)
		printf("%lld " , factors[i]);
	return 0;
}
