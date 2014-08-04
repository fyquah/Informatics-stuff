#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

bitset<1000010> bs;
vector<int> primes;
int sieve_size;

void sieve(int upper_bound){
	sieve_size = upper_bound;
	bs.reset();
	bs.flip();
	bs[0] = false;
	bs[1] = false;
	for(long long i = 2 ; i <= upper_bound ; i++)
		if(bs[i]){
			for(long long j = i * i ; j <= upper_bound ; j += i)
				 bs[j] = false;
			primes.push_back(i);
		}
}

bool isPrime(int N){
	if(N < sieve_size) return bs[N];
	else {
		for(int i = 0 ; i < primes.size() ; i++)
			if(N % primes[i] == 0) return false;
		return true;
	}
}

vector<int> primeFactors(int N){
	vector<int> factors;
	int prime_factor_index = 0;
	int prime_factor = primes[prime_factor_index];
	
	while(N != 1 && prime_factor * prime_factor <= N){
		while(N % prime_factor == 0){
			factors.push_back(prime_factor);
			N /= prime_factor;
		}
		prime_factor = primes[++prime_factor_index];
	}
	
	if(N != 1)
		factors.push_back(N);
		
	return factors;
}

int eulerTotientFunction(int N){
	vector<int> factors = primeFactors(N);
	vector<int>::iterator new_end = unique(factors.begin() , factors.end());
	int result = N;
	for(vector<int>::iterator it = factors.begin() ; it != new_end ; ++it)
		result -= result / *it;
	return result;
}

int main(){
	sieve(1000000);
	printf("%d\n" , isPrime(13));
	printf("%d\n" , isPrime(26));
	printf("%d\n" , isPrime(37));
	printf("%d\n" , eulerTotientFunction(36));
	vector<int> factors = primeFactors(36);
	for(int i = 0 ; i < factors.size() ; i++)
		printf("%d\n" , factors[i]);
	return 0;
}
