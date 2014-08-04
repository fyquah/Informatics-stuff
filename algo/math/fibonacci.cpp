#include <cstdio>
#include <vector>

std::vector<long long> found;
long long solve(int x){
	if(x == 0 || x == 1) return 1;
	if(found[x]!=0) return found[x];
	else return found[x] = solve(x-1) + solve(x-2);
}

int main()
{
	int n;
	try{
		for(int n = 1 ;  ; n++){
			found.resize(n+1 , 0);
			solve(n);
			if(n < 0) printf("There cannot be a negative fibonacci number!\n");
			else printf("%d" ,n);
			
		}
	}
	catch(std::bad_alloc e)
	{
		printf("shit number is %d \n" , n);
	}

}