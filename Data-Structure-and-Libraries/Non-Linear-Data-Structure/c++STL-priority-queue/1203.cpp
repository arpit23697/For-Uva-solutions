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

bool comparator ( tuple <int , int , int > a , tuple <int , int , int > b)
{
	if (get <0>(a) != get<0>(b))
		return get<0>(a) < get<0>(b);

		return	get<1>(a) < get<1>(b); 
}

int main ()
{
	
	string str;
	vector < tuple <int , int , int >> vec;


	while (1)
	{
		cin >> str;
		if (str == "#")
			break;

		int a , b;
		cin >> a >> b;
		vec.push_back (make_tuple (b , a , b));
	}

	int k;
	cin >> k;

	vector <tuple <int , int , int >> :: iterator itr;
	while (k--)
	{
		itr = min_element (vec.begin () , vec.end() , comparator);
		
		int index = itr - vec.begin();
		int minimum = get<0> (*itr);
		cout << get<1>(*itr) << endl;


		for (int i =0 ; i < vec.size() ; i++)
		{
			if (i != index)
			{
				if (get<0>(vec[i]) > 0)	
				get<0>(vec[i]) -= minimum;
			}
			else 
				get<0>(vec[i]) = get<2>(vec[i]); 
		}
		
		
	}



	return 0;
}