#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

bool comparator (char a , char b)
{
	if (tolower(a) == tolower(b))
		return a < b;

	return tolower(a) < tolower(b);
}
int main ()
{
	int test;
	char str[1000];
	cin >> test;

	while (test--)
	{
		cin.ignore();
		cin >> str;

		sort(str , str + strlen(str) , comparator);
		cout << str << endl;
		while (1)
		{
			if (next_permutation (str , str + strlen(str) , comparator))
				cout << str << endl;
			
			else
				break;
		}

		
	}

	return 0;
}