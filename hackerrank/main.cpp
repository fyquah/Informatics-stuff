# include <iostream>
# include <string>

using namespace std;

int main()
{
	string str;
	while(true)
	{
		getline(cin , str);
		for(long int k = 0 ; k < str.length() ; k++)
		{
			if(str[k] == '/' && str[k+1] == '/')
			{
				for(long int a = k ; a < str.length() ; a++) cout << str[a];
					cout << "\n";
				goto finish;
			}

			if(str[k] == '/' && str[k+1] == '*')
			{
				restart:
				getline(cin , str);
				if(str.empty()) goto restart;
				for(long int a = k ; a < str.length() ; a++)
				{
					cout << str[a];
					if(str[a] == '/' && str[a-1] == '*') goto finish;
				}
				goto restart;
			}
		}

		if(str.empty())
		{
			break;
		}
		finish:;
	}

	return 0;
}