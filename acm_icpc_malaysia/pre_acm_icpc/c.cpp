#include <iostream>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;
    for( ; N > 0 ; N--){
        string str;
        cin >> str;
        bool flag = true;
        for(int i = 0 , j = str.length() - 1 ; i < str.length() ; i++ , j--)
            if(str[i] != str[j]) {
                flag = false;
                break;
            }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
