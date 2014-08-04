#include "trie.h"
#include <iostream>

using namespace std;

void change(int & rx)
{
	rx = 1;
}

int main()
{
	Trie x;
	x.addWord("ALGORITHM");
	x.addWord("ALL");
	string str;
	while(true) {
		cin >> str;
		cout << x.countPrefix(str) << endl;
	}

	return 0;
}