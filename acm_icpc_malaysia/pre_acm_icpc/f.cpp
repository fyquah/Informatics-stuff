#include <iostream>
#include <cstring>
using namespace std;

int mat[1003][1003];

int main()
{
    for(int trial = 1 ; ; trial++){
        int N , M;
        cin >> N >> M;
        if(N == 0)
            break;
        memset(mat , 0 , sizeof(mat));
        string str;
        for(int i = 1 ; i <= N ; i++){
            cin >> str;
            for(int j = 1 ; j <= M ; j++){
                if(str[j-1] == '*'){
                    mat[i][j] = -100;
                    mat[i-1][j-1] += 1;
                    mat[i-1][j] += 1;
                    mat[i-1][j+1] += 1;
                    mat[i][j-1]  += 1;
                    mat[i][j+1] += 1;
                    mat[i+1][j-1] += 1;
                    mat[i+1][j] += 1;
                    mat[i+1][j+1] += 1;
                }
            }
        }
        cout << "Field #" << trial << ":\n";
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= M ;j++){
                if(mat[i][j] < 0) cout << "*";
                else cout << mat[i][j];
            }
            cout << "\n";
        }

    }
    return 0;
}
