/*

ID: fy.q1
LANG: C++
TASK: milk2
*/

# include <iostream>
# include <fstream>
# include <vector>
# include <algorithm>
# include <string>
# include <utility>

using namespace std;

int streak = 0;
int n;
int low_index = -1;
int mid_index = -1;
pair <int , int> times[5001];
int long_idle = 0;
int long_continue = 0;

int main()
{
    ifstream fin("milk2.in");
    fin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        fin >> times[i].first >> times[i].second;
    }
    fin.close();
    ofstream fout("milk2.out");
    sort(times , times + n);

    for(int i = 0 ; i < n ;i++)
    {
    	if(low_index == -1) {
    		low_index = i;
    		mid_index = i;
    		continue;
    	}
    	else {
    		if(times[i].second > times[mid_index].second && times[i].first <= times[mid_index].second){
    			mid_index = i;
    			continue;
    		}
    		else if(times[i].first < times[mid_index].second && times[i].second < times[mid_index].second) continue;
    		else if(times[i].first > times[mid_index].second)
    		{
    			if(long_continue < times[mid_index].second - times[low_index].first)
    				long_continue = times[mid_index].second - times[low_index].first;
    			if(times[i].first - times[mid_index].second > long_idle) long_idle = times[i].first - times[mid_index].second; 
    			mid_index = -1;
    			low_index = -1;
    			i--;
    		}
    	}
    }

    if(low_index != -1 && mid_index != -1)
    	if(long_continue < times[mid_index].second - times[low_index].first) 
    		long_continue =times[mid_index].second - times[low_index].first;
    if(times[n-1].second - times[n-1].first > long_continue) long_continue = times[n-1].second - times[n-1].first;

    fout << long_continue << " " << long_idle << "\n";
    fout.close();
}