#include <bits/stdc++.h>
using namespace std;

string convert_to_char(const int x){
	int exponent = floor(log10(x));
	
}

int main(int args , char * argv[]) {
	const int VIDEOS = args >= 2 ? atoi(argv[1]) : 1000000;
	const int VIEWS = args >= 3 ? atoi(argv[2]) : 1000000;
	vector<int> videos;
	vector<int> stats;
	stats.resize(10 , 0);
	videos.resize(VIDEOS , 0);

	int views_left = VIEWS;
	while(views_left){
		int target = rand() % VIDEOS;
		videos[target]+= 1;
		views_left--;
	}

	for(int i = 0 ; i < videos.size() ; i++){
		string num = convert_to_char(videos[i]);
		stats[(num[0] - '0')]++;
	}

	for(int i = 0 ; i < stats.size()  ;i++){
		cout << i << " -> " << stats[i] << "\n";
	}

	return 0;
}