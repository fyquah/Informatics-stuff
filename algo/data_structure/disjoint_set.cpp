#include "disjoint_set_class.h"
#include <iostream>
using namespace std;
int main()
{
	Disjoint_Union x(20);
	for(int i = 0 ; i < 20 ; i++)
		cout << "Set of " << i << " is " << x.find(i) << endl;
	x.merge(1,2);
	x.merge(1,3);
	x.merge(4,5);
	x.merge(1,6);
	x.merge(10,1);
	x.merge(10,19);

	for(int i = 0 ; i < 20 ; i++){
		cout << x.find(i) << endl;
	}

	cout << x.numberOfSets() << endl;

	return 0;
}

// #include <iostream>
// #include <vector>
// #include <cstring>
// #include <cmath>

// using namespace std;

// const int MAX_SIZE = 10;
// int disjoint[10];



// void merge(int i , int j){
// 	while(disjoint[i] >= 0)
// 		i = disjoint[i];
// 	while(disjoint[j] >= 0)
// 		j = disjoint[j];
// 	if(abs(disjoint[i]) > abs(disjoint[j])){
// 		disjoint[i] += disjoint[j];
// 		disjoint[j] = i;
// 	}
// 	else {
// 		disjoint[j] += disjoint[i];
// 		disjoint[i] = j;
// 	}
// }

// int find(const int * initial){
// 	int index = *initial;
// 	while(disjoint[index] >= 0)
// 		index = disjoint[index];

// 	disjoint[*initial] = index;

// 	return index;
// }

// int main()
// {
// 	memset(disjoint , -1  , sizeof(disjoint)); // they are now all individual sets
// 	merge(0,4);
// 	merge(1,2);
// 	merge(1,3);
// 	merge(1,4);
// 	for(int i = 0 ; i < 5 ; i++)
// 		cout << find(i) << "\n";
// 	return 0;
// }