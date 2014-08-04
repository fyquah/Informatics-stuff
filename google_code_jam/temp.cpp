#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int T;

int main()
{
	ifstream fin("test.in");
	ofstream fout("test.out");
	fin >> T;

	for(int trial = 0 ; trial < T ; trial++){
		vector <double> naomi1;
		vector <double> ken1;
		int N;

		fin >> N;
		for(int i= 0 ; i < N ; i++) {
			double x;
			fin >> x;
			naomi1.push_back(x);
		}
		for(int i = 0 ; i < N ; i++) {
			double x;
			fin >> x;
			ken1.push_back(x);
		}

		sort(naomi1.begin() , naomi1.end());
		sort(ken1.begin() , ken1.end());

		vector <double> naomi2 (naomi1.begin() , naomi1.end()); //to be used for deceitful war
		vector <double> ken2 (ken1.begin() , ken1.end());

		int war_score = 0;
		int decetiful_score =0;

		//in decetiful war, naomi knows all of Ken's blocks
		//she will say a weight that will force Ken is use his largest block
		//when naomi2[0] > ken2[ken2.size() - 1], she knows that she has nail it

		if(naomi1[naomi1.size()-1] < ken1[0]) goto end;

		//try to counter the highest possible of ken2 with the lowest possible of naomi2, only do this if it can be verified that 
		//the largest element of naomi2 is larger than that number, otherwise just erase the number  
		for(int i = 0 ; i < N ; i++){ //deceitful war
			if(ken2[ken2.size() -1] < naomi2[0]){
				decetiful_score += naomi2.size(); 
				break;
			}
			else if(ken2[ken2.size() - 1] > naomi2[naomi2.size() - 1]){
				ken2.pop_back();
				naomi2.erase(naomi2.begin());
			}
			else if(ken2[ken2.size() - 1] < naomi2[naomi2.size() - 1]){
				naomi2.erase(lower_bound(naomi2.begin() , naomi2.end() , ken2[ken2.size() -1]));
				ken2.pop_back();
				decetiful_score++;
			}
		}

		//In war, Naomi will definitely chose her biggest block to win
		//Ken, after knowing Naomi's choice, will definitely choose her biggest block too
		//If Ken doesnt have such block ,he will choose his smallest block

		for(int i =0  ;i < N ; i++){
			double naomi_choice = naomi1[naomi1.size() - 1];
			naomi1.pop_back();

			if(naomi_choice > ken1[ken1.size() - 1]){
				ken1.erase(ken1.begin());
				war_score++;
			}
			else{
				ken1.pop_back();
			}
		}
		end:
		fout << "Case #" << trial +1 << ": " << decetiful_score << " " << war_score << "\n";
	}

	return 0;
}