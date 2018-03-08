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

vector <pair <int , int>> vec;
pair <int , int> p1 , p2;
int matrix[20][2];
bool sol;
int n;
int m;
bool usedup[20];


void backtrack (int c)
{
	//cout << c << " ";
	if (c == n+1)
	{
		if (vec[c-1].second == p2.first)
		{
			sol = true;
			return;
		}

	}
	else
	{
		for (int i = 0; i < m ; i++)
		{
			if (usedup[i] == false)
			{
				int a = matrix[i][0];
				int b = matrix[i][1];
				bool flag = false;

				if (vec[c-1].second == a)
				{
					vec.push_back(make_pair (a , b));
					flag = true;
				}

				else if (vec[c-1].second == b)
				{
					vec.push_back (make_pair (b , a));
					flag = true;
				}

				if (flag)
				{
					usedup[i] = true;
					backtrack(c+1);
					usedup[i] = false;
					vec.erase (vec.end()-1);
				}

	//			for (int i =0 ; i < vec.size() ; i++)
	//				cout << "("<<vec[i].first << "," << vec[i].second <<")" << " ";

	//			cout << endl;


			}
		}
	}
}


int main ()
{
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;

		cin >>  m;

		int a , b;
		cin >> a >> b;
		p1 = make_pair (a , b);

		cin >> a >> b;
		p2 = make_pair (a , b);

		for (int i = 0 ; i < m ; i++)
			cin >> matrix[i][0] >> matrix[i][1];

		

		vec.clear();
		vec.push_back (p1);
		sol = false;
		memset (usedup , false , sizeof usedup);
		backtrack(1);

		if (sol == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}

	return 0;
}