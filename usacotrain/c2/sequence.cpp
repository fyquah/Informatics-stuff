#include <cstdio>
#include <cstring>

int main()
{
	int N, sequence[10010] , bestrun[10010]; //best run contins information on the heading (smallest) element
	scanf("%d" , &N);
	for(int i = 0 ; i < N ; i++)
		scanf("%d" , sequence + i);

	int best = 1; // best refers to the maximum length based on the current array
	memset(bestrun , 0 , sizeof(bestrun));
	bestrun[1] = sequence[N-1];

	for(int i = N-1-1 ; i >= 0 ; i--) {
		if(sequence[i] < bestrun[1]){
			bestrun[1] = sequence[i];
			continue;
		}
		
		for(int j = best ; j> 0 ; j--){
			if(sequence[i] > bestrun[j])
				if(j == best || bestrun[j+1] > sequence[i]){
					bestrun[++j] = sequence[i];
					if(j == best + 1) best++;
					break; 
				}
		}

	}

	printf("%d\n" , best);
	return 0;
}