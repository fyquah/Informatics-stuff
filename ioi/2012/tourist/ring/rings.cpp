#include <math.h>

int N;
int set[1000000];

void Init(int count) {
	N = count;
	memset(set , -1 , (n+10) * sizeof(set[0]));

}

void Link(int A, int B) {
	if(abs(set[A]) > abs(set[B])){
		set[B] = A;
	}
	else {
		set[A] = B;
	}
}

int CountCritical() {

  return N;

}
