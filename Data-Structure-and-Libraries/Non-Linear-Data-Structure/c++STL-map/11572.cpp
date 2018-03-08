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
#include <stack>
#include <tuple>
#include <deque>
#include <map>

using namespace std;

int main ()
{
	int test;
	cin >> test;

	while (test--)
	{
		map <long long int ,long long int > myMap;
		long long int cases;
		cin >> cases;

		pair <map <long long int , long long int > :: iterator , bool> pair_retrieve;
		long long int ans = 0;
		long long int ar[cases+1];
		

		for (long long int i =0 ; i < cases ; i++)
			cin >> ar[i];
		

		long long int finalAnswer = 0;


		for (int i =0 ; i < cases ; i++)
		{
			ans = 0;
			int flag = 0;
			int j;
			myMap.erase(myMap.begin() , myMap.end());
			for ( j = i ; j < cases ; j++ )
			{
			
				pair_retrieve = myMap.insert ( make_pair (ar[j] , 1));

				if (flag == 0 && pair_retrieve.second == true)
					ans++;

				if (pair_retrieve.second == false)
				{
					flag = 1;
					if (ans <= myMap.size())
					ans = myMap.size(); 

					myMap.erase(myMap.begin() , myMap.end());
				}
				pair_retrieve = myMap.insert ( make_pair (ar[j] , 1));

			}

			finalAnswer = max (ans , finalAnswer);

			if (cases - i < finalAnswer)
				break;
		}

		cout << finalAnswer << endl;
	}

	return 0;
}