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
#include <set>
#include <queue>

using namespace std;

int a[15] , n , t , ans;
bool usedup[15];
int tempSum;

set <vector <int>> myset;

void backtrack ()
{

	if (tempSum == t)
	{
		ans++;
		vector <int> vec;
		for (int i =0 ; i < n ; i++)
			if (usedup[i] == true)
				vec.push_back (a[i]);

		myset.insert (vec);
		/*
		int size = vec.size();
		for (int i =0 ; i < size ; i++)
		{
			if (i < size - 1)
				cout << vec[i] << " ";
			else
				cout << vec[i] <<endl;
		}
		*/
	}

	else
	{
		for (int i =0 ; i < n ; i++)
		{
			if (tempSum + a[i] <= t && usedup[i] == false)
			{
				cout << tempSum << " " ;
				tempSum += a[i];
				usedup[i] = true;
				backtrack ();
				usedup[i] = false;
				tempSum -= a[i];
			}
		}
	}
}


int main ()
{
	while (1)
	{


		cin >> t;
		cin >> n;

		if (n == 0)
			break;


		for (int i = 0 ; i < n ; i++)
			cin >> a[i];

		myset.clear();
		ans = 0;
		tempSum = 0;
		memset (usedup , false , sizeof usedup );
		backtrack();




		cout << "Sums of " << t << ":" <<endl;
		if (ans == 0)
			cout << "NONE" << endl;
		else
		{
			for (set <vector <int>> :: reverse_iterator itr = myset.rbegin() ; itr != myset.rend() ; ++itr)
			{
			int size = (*itr).size();
			for (int i =0 ; i < size ; i++)
			{
				if (i < size - 1)
					cout << (*itr)[i] << "+";
				else
					cout << (*itr)[i] <<endl;
			}
			
			}
		}
	}

	return 0;
}