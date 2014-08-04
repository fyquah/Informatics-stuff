/*

ID: fy.q1
LANG: C++
TASK: transform
*/

# include <iostream>
# include <fstream>
# include <vector>
# include <algorithm>
# include <string>
# include <utility>

using namespace std;

int n;
string ori[10];
string x[10];
string y[10];

//there are only four possible forms of transformation - 90 degree , 180 degree, 270 degree and reflection
// combination is not considered as a form, but will be part of the tests

bool test_same(string str[10])
{
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ;j++)
            if(str[i][j] != ori[i][j]) return false;
    return true;

}

bool test_180(string str[10])
{
    for(int i = 0  ; i < n ;i++)
        for(int j = 0 ; j < n ; j++)
            if(str[i][j] != ori[n-1-i][n-j-1]) return false;
        cout << "180" << endl;
    return true;
}

bool test_90(string str[10])
{
    for(int i = 0 ; i < n ; i++)
        for(int j  = 0 ; j < n ;j ++)
            if(str[i][j] != ori[n-1-j][i]) return false;
        cout << "90" << endl;
    return true;
}


bool test_270(string str[10])
{
    for(int i =0 ; i < n; i++)
        for(int j = 0 ; j < n ;j++)
            if(str[i][j] != ori[j][n-1-i]) return false;
        cout << "270" << endl;
    return true;
}

bool test_reflect(string str[10])
{
    for(int i = 0 ; i < n; i++)
        for(int j =0 ; j <n ;j++)
            if(str[i][j] != ori[i][n-1-j]) return false;
    return true;
}

int main()
{
    ifstream fin("transform.in");
    fin >> n;
    for(int i = 0 ; i < n ; i++)
        fin >> ori[i];
    for(int i =0 ; i < n; i++)
        fin >> x[i];
    fin.close();


    ofstream fout("transform.out");


   

    if(test_90(x))
        fout << 1 << "\n";
    else if(test_180(x))
        fout << 2 << "\n";
    else if (test_270(x))
        fout << 3 << "\n";
    else if (test_reflect(x))
        fout << 4 << "\n";
    else
    {
        for(int i = 0 ; i < n ;i++)
            for(int j = 0 ; j < n ; j++)
                y[i] += (x[i][n-1-j]);

        if(test_90(y) || test_270(y) || test_180(y)) fout << 5 << "\n";
        else if (test_same(x)) fout << 6 << "\n";
        else fout << 7 << "\n";
    }

    end:
    fout.close();
}