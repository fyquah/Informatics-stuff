#include "advisor.h"
void ComputeAdvice(const int *C, int N, int K, int M) {
	

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < C[i]; ++j) {
			WriteAdvice(1);
		}
		WriteAdvice(0);
	}

}
