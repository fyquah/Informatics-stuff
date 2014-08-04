#include <algorithm>
#include <cstdio>
using namespace std;

int T;
FILE * cin;
FILE * cout;

int main()
{
	cin = fopen("test.in" , "r");
	cout = fopen("test.out" , "w");
	fscanf(cin , "%d" , &T);
	for(int trial = 0 ; trial < T ; ++trial){
		double C , F , X;
		fscanf(cin , "%lf %lf %lf" , &C , &F , &X);
		double current_time = 0.0;
		double current_rate = 2.0;
		while(1 < 2)
		{
			if(X / current_rate < (C / current_rate + X/(current_rate + F)) ) {
				current_time += X/current_rate;
				fprintf(cout , "Case #%d: %.7f\n" , trial + 1 , current_time);
				break;
			}
			else {
				current_time += C/current_rate;
				current_rate += F;
			}
		}
	}
	return 0;
}