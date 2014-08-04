/*

ID: fy.q1
LANG: C++
TASK: taskname
*/
# include <iostream>
# include <fstream>
# include <algorithm>
# include <utility>
# include <vector>
# include <string>
# include <stdio.h>
# include <string>
# include <stdlib.h>
# include <sstream>
# include <math.h>

using namespace std;

FILE *fout;
FILE *fin;

int main(void)
{
   fin = fopen("pprime.in", "r");
   fout = fopen("pprime.out", "w");

   fscanf(fin, "%ld %ld", &a, &b);

   return 0;
}