#include <fstream>
using namespace std;

int T;

int main()
{
	ifstream cin("test.in");
	ofstream cout("test.out");
	cin >> T;
	for(int trial = 0 ; trial < T ; trial++){
		int r1 ,r2;
		int pos1[4][4];
		int pos2[4][4];

		cin >> r1;
		r1--;
		for(int i = 0 ;i < 4 ; i++)
			for(int j = 0 ; j < 4 ;j++)
				cin >> pos1[i][j];

		cin >> r2;
		r2--;
		for(int i = 0 ;i < 4 ; i++)
			for(int j = 0 ; j < 4 ;j++)
				cin >> pos2[i][j];

		int number_matched = 0;
		int occurence = 0;

		for(int i = 0 ; i < 4 ; i++)
			for(int j = 0 ; j < 4 ;j++)
				if(pos1[r1][i] == pos2[r2][j]){
					++occurence;
					number_matched = pos1[r1][i];
				}

		cout << "Case #" << trial + 1 << ": ";
		if(occurence == 0)  cout << "Volunteer cheated!\n";
		else if (occurence == 1) cout << number_matched << "\n";
		else if (occurence > 1) cout << "Bad magician!\n";

	}
	return 0;	
}