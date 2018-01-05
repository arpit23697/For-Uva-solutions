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

	for (int m  = 0 ; m <  test ; m++)
	{

		string str;

		if (m == 0)
			cin.ignore();
		getline (cin , str);

		string data;
		for (int i =0 ; i < str.length () ; ++i)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				data.push_back (str[i]);
		}

		int len = data.length ();
		long long int k =  sqrt (len);

		bool isMagicPalindrome = false;

		if ( k * k == len)
		{
			isMagicPalindrome = true;
		}
		char matrix [k][k];
		if (isMagicPalindrome == true)
		{
			for (int i = 0 ; i < k ; i++)
			{
				for (int j = 0 ; j  <k ; j++)
				{
					matrix[i][j] = data[i*k + j];
				}
			}
		}

		string str1 , str2 , str3 ;
		//checking the magic palindrome
			
			if (isMagicPalindrome == true)
			{
			for (int j= 0 ; j < k ; j++)
				for (int i =0 ; i < k ; i++)
					str1.push_back(matrix[i][j]);

			for (int i= k-1 ; i >= 0 ; i--)
				for (int j =k-1 ; j >= 0 ; j--)
					str2.push_back(matrix[i][j]);

			for (int j= k-1 ; j >= 0 ; j--)
				for (int i = k-1 ; i >= 0 ; i--)
					str3.push_back(matrix[i][j]);
			}
		//	cout << k << "  " << data << "  " << str1 << " " << str2 << " " << str3 << endl;

			if (data == str1 && data == str2 && data == str3)
				isMagicPalindrome = true;
			else
				isMagicPalindrome = false;

			cout << "Case #" << m+1 << ":" << endl;
			if (isMagicPalindrome == true)
				cout << k << endl;

			else
				cout << "No magic :(" << endl;

	}

	return 0;
}