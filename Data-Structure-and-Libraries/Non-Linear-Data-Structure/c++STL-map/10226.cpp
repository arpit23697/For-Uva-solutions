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

	cin.ignore (100 , '\n');
	cin.ignore (100 , '\n');

	for (int m = 0 ; m < test ; m++)
	{
		long long int total = 0;
		map < string , double > myMap;
		pair < map <string , double > :: iterator , bool>  pair_retrieve;

		while (cin.peek () != '\n' && cin.peek() != -1)
		{
			
			string str;
			getline (cin , str);
			total++;
		
			pair_retrieve = myMap.insert (make_pair (str , 1));

			if (pair_retrieve.second == false)
				myMap[str]++;
		}

		cin.ignore (100 , '\n');
		

		for (map <string , double> :: iterator itr = myMap.begin() ; itr != myMap.end() ; ++itr)
		{	
		
			cout << itr -> first << " "; 
			double ans = itr -> second / total * 100;
			printf("%.4lf\n",ans);
		}

		if (m < test-1)
			cout << endl;

	}

	return 0;
}