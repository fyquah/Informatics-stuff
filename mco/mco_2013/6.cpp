#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;

int T;


int main()
{

	cin >> T;
	for(int trial = 0 ; trial < T ; trial++){
		int N, M , K , Q ;
		int a[100001];
		int b[100001];
		string all[301];
		cin >> N >> M >> K;

		for(int i= 0 ; i < N ; i++)
			cin >> all[i];

		cin >> Q;

		for(int i = 0 ; i < Q  ;i++)
			cin >> a[i] >> b[i];
		
		for(int i =  0 ; i < N ; i++){
			int ans = 0;

			for(int r = 1 ; r <= a[i] ; r++)
				for(int c = 1 ; c <= b[i] ; c++) {

					//now try the row and limit thingy
					//1. select different starting points
					//2. sum up all the honey inside

					for(int y = 0 ; y < N - r + 1 ; y++)
						for(int x = 0 ; x < M-c+1 ; x++) {
							for(int p = 0 ; p < r ; p++)
								for(int q = 0 ; q < c ; q++)
									if(all[y + p][x + q] == 'H') ans++;
						}
				}

			cout << ans << "\n";
		}

	}

	return 0;
}