//There are several ways to do binary search
//some of the main ones are as below:
/*

1) You want to look for the element
2) You want to look for the first occurence of the element
3) You want to look for the last occurence of the element

Cases such as wanting to find the first element larget than that is not included, because it is just vague.
*/

# include <iostream> // std::printf
# include <algorithm> //binary search and sort
# include <string> // YES, YOU CAN SORT STRINGS

int x[] = [1,2,4,5,6,7,8,9,10,15,19,25];

//This is the normal search function assuuming there are no repeatation, the algo has a problem, as it cannot really detect whether the thing is not, an option is to initialize a return value for a failed binary search
int search(int search_term)
{
	int lo, high, mid;
	high = sizeof(x) - 1;
	lo = 0;
	mid = (high + lo)/2;
	while(lo < high)
	{
		if(x[mid] == search_term) return mid;
		else if (x[mid] < search_term) lo = mid + 1;
		else if (x[mid] > search_term) high = mid;

		mid =(lo + high) / 2;
	}

	return lo;
}

int search_first_occur(int search_term)
{
	int lo, high, mid;
	high = sizeof(x) - 1;
	lo = 0;
	mid = (high + lo)/2;
	while(lo < high)
	{
		if (x[mid] < search_term) lo = mid + 1;
		else if (x[mid] >= search_term) high = mid;

		mid =(lo + high) / 2;
	}

	return mid; 
}

int search_last_occur(int search_term)
{
	int lo, high, mid;
	high = 11;
	lo = 0;
	mid = (high + lo)/2;
	while(lo < high)
	{
		if (x[mid] < search_term) lo = mid + 1;
		else if (x[mid] == search_term){
			lo = mid;
			if(x[lo + 1] != search_term) return lo;
		}
		else if (x[mid] > search_term) high = mid;

		mid =(lo + high) / 2;
	}

	return mid; 
}
//all the aboce algrithm neglects the possibility that the term cannot be found, but that will only have to considered on actual coding

int main()
{
	sort(x , x + 12);
	return 0;
}