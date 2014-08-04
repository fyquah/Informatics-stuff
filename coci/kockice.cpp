#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long a[300001];
long long b[300001];

long long fnc(int x) //x is the minimal value
{
	long long ret = 0;
	for(int i =0 ; i < N ; i++){
		ret += abs(a[i] - abs(i-N/2));
		ret += abs(b[i] - abs(i-N/2));
	}
	return ret;
}

int main()
{
	cin >> N;
	for(int i =0 ; i < N ;i++)
		cin >> a[i];
	for(int i =0 ; i < N ;i++)
		cin >> b[i];

	long long lo = 0;
	long long high = 0;
	for(int i= 0 ; i < N ; i++)
		high = max(high , max(a[i] , b[i]));
	long long mid;

	while(lo != high) {
		mid =(lo + high) /2;
		if(fnc(mid) < fnc(mid + 1)) high = mid;
		else if (fnc(mid) >= fnc(mid + 1)) low = mid + 1;
	}

	cout << fnc(lo) << "\n";

	return 0;
}