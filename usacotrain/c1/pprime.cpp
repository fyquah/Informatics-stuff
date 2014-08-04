/*

ID: fy.q1
LANG: C++
TASK: pprime
*/
# include <iostream>
# include <fstream>
# include <algorithm>
# include <utility>
# include <vector>
# include <string>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

FILE *fout;
long a, b;
bool okay = true;

string conint(int number)
{
	stringstream ss;
	ss << number;
	return ss.str();
}

bool isprime(long n)
{
   long i;

   if(n == 2)
   return true;

   if(n%2 == 0)
   return false;

   for(i=3; i*i <= n; i+=2)
   if(n%i == 0)
       return false;

   return true;
}

void gen(int i)
{
   string forward = conint(i);
   string reverse = "";
   for(int j = 0 ; j < forward.length() ; j++)
   		reverse += forward[forward.length() - 1- j];

   string temp = forward + reverse;
   long x = atol(temp.c_str());
   if((x >= a) && isprime(x) && x <= b){
   	fprintf(fout , "%ld\n", x);
   	cout << x << endl;
   } 
   if(x > b) {
   	okay = false;
   	return;
   }

   for(int y = 0 ; y < 10 ; y++){
   		temp = forward + conint(y)  + reverse;
   		x = atol(temp.c_str());
   		if(isprime(x) && (x >= a) && (x <= b)){ 
   			fprintf(fout, "%ld\n",x);
   	   	}
   		if(x > b) {
		   	okay = false;
		   	return;
		  }
   }
}


int main(void)
{
   FILE *fin;

   fin = fopen("pprime.in", "r");
   fout = fopen("pprime.out", "w");

   fscanf(fin, "%ld %ld", &a, &b);

   //check if 5 and 7 is in the range
   if(a <= 7)
   {
   		if(a == 5) fprintf(fout, "%d\n", 5);
   		fprintf(fout, "%d\n", 7);
   }
   for(int i = 1 ; i <= 9999 ; i++)
   {
   		gen(i);
   		if(okay== false) break;

   };


   return 0;
}