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
	while(1)
	{
		long long int cases;
		cin >> cases;

		if (cases == 0)
			break;

		map < tuple <int , int , int , int , int> , int> myMap;

		pair <map < tuple <int , int , int , int , int> , int > :: iterator , bool> pair_retrieve;
		for (long long int i = 0; i < cases ; i++)
		{
			int ar[5] ;
			cin >> ar[0] >> ar[1] >> ar[2] >> ar[3] >> ar[4];

			sort (ar , ar+5);
			pair_retrieve = myMap.insert (make_pair (make_tuple (ar[0] , ar[1] , ar[2] ,ar[3] ,ar[4]) , 1));

			if (pair_retrieve.second == false)
				myMap[make_tuple (ar[0] , ar[1] , ar[2] ,ar[3] ,ar[4])]++;
		}

		int ans = 0;
		int most_popular = 0;
		for (map < tuple <int , int , int , int , int> , int> :: iterator itr = myMap.begin() ; itr != myMap.end() ; ++itr)
		{
			if (itr -> second > most_popular)
			{
				most_popular = itr -> second;
				ans = itr -> second;
			}

			else if (itr -> second == most_popular)
			{
				most_popular = itr -> second;
				ans += most_popular;
			}
		}

		cout << ans << endl;
		
	}

	return 0;
}