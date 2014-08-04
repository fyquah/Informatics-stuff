// O(log10 N)
#include <cstdio>

int gcd(int a, int b){
	if(a < b){
		a = a ^ b;
		b = b ^ a;
		a = a ^ b;
	}
	return (b == 0) ? a : gcd(b , a % b); 
}

int lcm(int a, int b){
	if(a < b){ 
	return (a * (b / gcd(a,b)));
}

int main()
{
	printf("%d\n" , lcm(9,33));
	return 0;
}
