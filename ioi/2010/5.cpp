#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <math.h>

using namespace std;

void play(){
	int candy = 0;
	pair<int ,int> locate[25];
	memset(locate , make_pair(0,0) , sizeof(locate));
	char all[51];
	memset(all , 0 , sizeof(all));

	for(int i = 1 ;i <= 50 ; i++){
		all[i] = faceup(i);
		if(locate[all[i]-65].first == 0) locate[all[i]-65].first = i;
		else locate[all[i]-65].second = i;
	} // 50 calss

	for(int i = 0 ; i < 25 ; i++){
		faceup(all[i].first);
		faceup(all[i].second);
	} // 2 * 25 calls

	return;
}

int main()
{

}