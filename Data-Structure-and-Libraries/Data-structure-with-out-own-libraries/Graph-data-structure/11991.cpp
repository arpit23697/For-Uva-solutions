//important

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

int main ()
{
	long long int n , queries;
	while (scanf ("%lld %lld" ,&n,&queries) == 2)
	{

		vector <vector <int>> vec;	
		vec.assign (1000000 , vector <int> ());
		
		for (int i =0 ; i < n ; i++)
		{
			int temp;
			cin >> temp;
			vec[temp].push_back (i+1);
		}

		for (int i = 0 ; i < queries ; i++)
		{
			int k , num;
			cin >> k >> num;
			if (k-1 < vec[num].size())
				cout << vec[num][k-1] << endl;

			else
				cout << "0" << endl;
				
		} 


	}

	return 0;
}