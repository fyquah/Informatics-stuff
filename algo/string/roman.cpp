/*
ID: fy.q1
LANG: C++
TASK: preface
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

int cnt[256];
string r = " IVXLCDM";

struct roman_t{
	int value;
	string roman;
};

roman_t data[14] = {
    1000, "M",
    900, "CM",
    500, "D",
    400, "CD",
    100, "C",
    90, "XC",
    50, "L",
    40, "XL",
    10, "X",
    9, "IX",
    5, "V",
    4, "IV",
    1, "I"
};

string itor(int num)
{
    string result="";
    for (int i=0;i<13;i++){
    	while(num >= data[i].value){
    		result += data[i].roman;
    		num -= data[i].value;
    	}
        if(num == 0) break;
    }
    return result;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
    int N;
    cin >> N;
  
  	for(int i = 1 ; i <= N ; i++){
  		string str = itor(i);
  		for(int j = 0 ; j < str.length() ; j++)
  			cnt[str[j]]++;
  	}

  	for(int i = 0 ; i < r.size() ; i++)
  		if(cnt[r[i]]) cout << r[i] << " " << cnt[r[i]] << "\n";

    return 0;
}