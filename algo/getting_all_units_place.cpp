bool check(int a)
{
	for(int i = 10; a != 0 ; i = i * 10)
	{
		int x = (a % i) * 10 / i ;
		cout << x << " ";
		for(int j = 0 ; j < n ;j++)
			if(x == all[j]) goto okay;
		return false;
		okay:
		a -= x * i / 10;
	}
	return true;
}