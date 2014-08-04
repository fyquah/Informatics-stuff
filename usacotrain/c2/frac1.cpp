/*
ID: fy.q1
LANG: C++
TASK: frac1
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
using namespace std;

struct Frac
{
	int num;
	int denom;
	double value;
	bool operator<(Frac const &test) const{
		return value < test.value;
	}
	Frac (int num , int denom , double value) : num(num) , denom(denom) , value(value) {}
};

vector <vector <int> > prime_factors (161);
int N;
vector <Frac> all;

bool isPrime(int x){
	if(x == 1) return false;
	if(x == 2) return true;
	if(x % 2== 0) return false;
	for(int i = 3 ; i * i <= x ; i+=2)
		if(x % i== 0) return false;
	return true;
}

bool check_simplify(int num , int denom){
	for(int i = 0 ; i < prime_factors[num].size() ; i++)
		if(denom % prime_factors[num][i] == 0) return false;
	return true;
}

int main(void)
{
	freopen("frac1.in" ,"r" , stdin);
	freopen("frac1.out" , "w" , stdout);
	ios_base::sync_with_stdio(false);
	cin >> N;

	for(int i = 1 ; i <= 160 ; i++){
		if(isPrime(i)) continue;
		if(i % 2 == 0) prime_factors[i].push_back(2);
		for(int j =3 ; j < i ;j+=2)
			if(i % j ==0 && isPrime(j)) prime_factors[i].push_back(j);
	}

	//only push fractions of the simplest form into the vector 'all'
	//denom and num must be coprime

	for(int i = 1 ; i <= N ;i++){ //denominator
		for(int j = 1 ; j < i ; j++){ //numerator
			if(i % j == 0 && j !=1) continue;
			if(j!= 1 && (!check_simplify(j,i) || i%j == 0)) continue;
			double value = (j+0.0) / (i+0.0);
			all.push_back(Frac(j,i,value));
		}
	}
	all.push_back(Frac(0,1,0.0));
	all.push_back(Frac(1,1,1.0));
	sort(all.begin() , all.end());

	for(int i = 0 ; i < all.size() ; i++)
		cout << all[i].num << "/" << all[i].denom << "\n";

	return 0;
}