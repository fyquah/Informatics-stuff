/*
ID: fy.q1
LANG: C++
TASK: concom
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define NCOM 101

using namespace std;

bool control[101][101]; //control[i][j] => i owns j for (some) %
int own[101][101];

void addController(int a , int b){
	if(a == b)
		return;
	if(control[a][b])
		return;
	control[a][b] = true;

	for(int i = 1 ; i < NCOM ; i++) //transfer of stakes
		own[a][i] += own[b][i];

	for(int i = 1 ; i < NCOM ; i++) //transfer of ownership
		if(control[b][i])
			addController(a,i);

	for(int i = 1 ; i < NCOM ; i++) //being owned by new companies
		if(control[i][a])
			addController(i ,b);

	for(int i = 1 ; i < NCOM ; i++) //forming new ownerships
		if(own[a][i] > 50)
			addController(a,i);
}

void addOwner(int a , int b , int c){
	if(a == b)
		return;

	for(int i = 1 ; i < NCOM ; i++)
		if(control[i][a])
			own[i][b] += c;

	for(int i = 1 ; i < NCOM ; i++)
		if(own[i][b] > 50)
			addController(i,b);
}

int main()
{
	freopen("concom.in" , "r" , stdin);
	freopen("concom.out" , "w" , stdout);
	
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	for(int i = 1 ;i < NCOM ; i++)
		control[i][i] = true;

	for(int i = 0 ; i < n ; i++){
		int a,b,c;
		cin >> a >> b >> c;
		addOwner(a,b,c);
	}

	for(int i = 1 ; i< NCOM ; i++)
		for(int j = 1; j < NCOM ; j++)
			if(i != j && control[i][j])
				cout << i << " " << j << "\n";

	return 0;
}

// void addController(int new_owner , int controlled){
// 	if(new_owner == controlled)
// 		return;
// 	if(control[new_owner][controlled])
// 		return;
// 	control[new_owner][controlled] = true;

// 	for(int i = 1 ; i < NCOM ; i++)
// 		own[new_owner][i] += own[controlled][i];

// 	for(int i = 1 ; i < NCOM ; i++)
// 		if(control[i][controlled])
// 			addController(i , controlled);

// 	for(int i = 1 ; i < NCOM ; i++)
// 		if(own[new_owner][i] > 50)
// 			addController(new_owner , i);

// }

// void addOwner(int a , int b , int c){
// 	if(a == b)
// 		return;

// 	for(int i = 1 ; i < NCOM ; i++)
// 		if(control[i][a])
// 			own[i][b] += c;

// 	for(int i = 1 ; i < NCOM ; i++)
// 		if(own[i][b] > 50)
// 			addController(i,b);
// }

// int main(){
// 	ios_base::sync_with_stdio(false);

// 	memset(control , false , sizeof(control));
// 	memset(own , 0 , sizeof(own));
	
// 	for(int i = 1 ; i < NCOM ; i++)
// 		control[i][i] = true;

// 	int N;
// 	cin >> N;

// 	for(int i = 0 ; i < N ; i++){
// 		int c , b , a;
// 		cin >> a >> b >> c;
// 		addOwner(a,b,c);
// 	}

// 	for(int i = 1 ; i < NCOM ; i++)
// 		for(int j = 1 ; 	j < NCOM ; j++)
// 			if(i != j && control[i][j])
// 				cout << i << " " << j << "\n";
// 	return 0;
// }