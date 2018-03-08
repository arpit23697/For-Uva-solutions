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

bool check (int a[])
{
//	cout << "Hi there";
	for (int i =0 ; i < 26 ;i++)
		if (a[i] != 0)
			return false;

		return true;
}


int main ()
{
	while (1)
	{
		int testCase;
		cin >> testCase;

		if (testCase == -1)
			return 0;

		string str;
		string guess;
		cin >> str;

		int a[26];
		for (int i =0 ; i<26 ;i++)
			a[i] = 0;

		for (int i =0 ; i < str.length() ; i++)
			a[str[i] - 'a']++;

		int copy[26];
		for (int i =0 ; i < 26 ; i++)
		{
		//	cout << a[i] << "  " << endl;	
			copy[i] = a[i];
		}
		cin >> guess;

		int countdown = 7;
		for (int i =0 ; i < guess.length() ;i++)
		{
			char temp = guess[i];
			if (a[temp - 'a'] == 0)
				countdown--;

			else
			{
				copy[temp - 'a'] = 0;
				if (check(copy))
					break;
			}
		}



		if (countdown > 0)
		{
			if (check(copy) == true)
			{
				cout << "Round " << testCase << endl;
				cout << "You win." << endl; 
			}

			else
			{
				cout << "Round " << testCase << endl;
				cout << "You chickened out." << endl;
			}
		}
		else
		{
			cout << "Round " << testCase << endl;
			cout << "You lose." << endl;
		}
	}

	return 0;
}
