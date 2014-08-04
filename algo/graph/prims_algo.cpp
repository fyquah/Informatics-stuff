#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

int T;
struct Town
{
	int x,y,m;
} all[1001];
double matrix[1001][1001];

int main() {
    cin >> T;
    cout << fixed;
    cout.precision(2);
    for(int trial = 0 ; trial < T ; trial++){
    	int N;
    	double distance[1001];
        double max_money = 1e9;
        double max_money_index;
    	cin >> N;

    	for(int i = 0 ; i < N ; i++){
    		cin >> all[i].x >> all[i].y >> all[i].m;
            if(all[i].m < max_money) {
                max_money_index = i;
                max_money = all[i].m;
            }
        }
    	for(int i= 0 ; i < N ;i++)
    		for(int j = i + 1 ; j < N ; j++)
    			matrix[i][j] = matrix[j][i] = sqrt(pow(all[i].x - all[j].x,2) + pow(all[i].y - all[j].y, 2));

    	//select a starting node for prim's algorithm

    	bool visited[1001];
    	memset(visited , false , sizeof(visited));
    	double ans = max_money;

        for(int i = 0 ; i < N ;i++)
            distance[i] = matrix[0][i];

        visited[0] = true;
        int cur = 0;
        int next = N-1;

        /*
        for(int i =0 ; i < N ; i++)
        {
            for(int j = 0;  j < N ;j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }
        */

        for(int i = 1 ; i < N ; i++){
            
            //update all the shortest distances value
            
            double shortest_distace = 1e9;

            for(int j = 0 ; j < N ;j++){
                if(!visited[j]){
                    if(distance[j] > matrix[cur][j])  distance[j] = matrix[cur][j];
                    if(distance[j] < shortest_distace) {
                        shortest_distace = distance[j];
                        next = j;
                    }
                }
            }
            visited[next] = true;
            cur = next;
            ans += shortest_distace;
        }
        
        //now to add in the differences
        double diff = 1e9;
        for(int i = 0 ; i < N ; i++)
        {
            if(i == max_money_index) continue;
            diff = min(diff , all[i].m-distance[i]);
        }
    	cout << ans + diff<< "\n";
    }
    return 0;
}

