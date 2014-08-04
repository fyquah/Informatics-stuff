#include <cstdio>

int main()
{
	int a = 10;
	int b = 20;
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
	printf("%d %d" , a , b);
	return 0;	
}