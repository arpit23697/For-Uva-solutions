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

int main ()
{
	int test;
	cin >> test;
	while (test--)
	{
		vector <char> characters;
		vector <double> values;

		int m;
		cin >> m;
		for (int i =0 ; i < m ; i++)
		{
			char temp;
			int val;
			cin >> temp >> val;
			characters.push_back(temp);
			values.push_back(val/100.0);
		}

		cin >> m;
			cin.ignore();
		double ans = 0;
		for (int i =0 ; i < m ; i++)
		{
			string str;
		
			getline (cin , str);
			

			for (int j = 0; j < characters.size() ; j++)
			ans += count (str.begin() , str.end() ,  characters[j]) * values[j];
		}

		printf("%.2f$\n",ans);
	}

	return 0;
}