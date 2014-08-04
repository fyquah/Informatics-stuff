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

int ans[256];

struct roman_t{
    int value;
    string roman;
    roman_t(int value ,string roman) : value(value) , roman(roman){}
};

roman_t all[13] = {
    roman_t(1000,"M"),
    roman_t(900,"CM"),
    roman_t(500,"D"),
    roman_t(400,"CD"),
    roman_t(100,"C"),
    roman_t(90,"XC"),
    roman_t(50,"L"),
    roman_t(40,"XL"),
    roman_t(10,"X"),
    roman_t(9,"IX"),
    roman_t(5,"V"),
    roman_t(4,"IV"),
    roman_t(1,"I"),
};

string itor(int x){
    string result="";
    for(int i = 0 ; i < 13 ; i++){
        while(x >= all[i].value) {
            x-=all[i].value;
            result+=all[i].roman;
        }
        if(x == 0) break;
    }
    return result;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("preface.in","r",stdin);
    freopen("preface.out","w",stdout);
    string r = " IVXLCDM";
    int N;
    cin >> N;
    for(int i =1 ; i <= N ; i++){
        string str = itor(i);
        for(int j = 0 ; j < str.size() ; j++)
            ans[str[j]]++;
    }

    for(int i = 0 ; i < r.length() ; i++)
        if(ans[r[i]]) cout << r[i] << " " << ans[r[i]] << "\n";
    return 0;
}