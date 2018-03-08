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
	int test;
	cin >> test;

	while (test--)
	{
		int n;
		cin >> n;

		vector <vector <int>> matrix;
		matrix.assign (n , vector <int> ());

		for (int i =0 ; i < n ; i++)
			for (int j = 0 ; j < n ; j++)
			{	
				int temp;
				cin >> temp;
				matrix[i].push_back (temp);
			}


		vector <int> vec;
		for (int i =0 ; i < n ; i++)
			vec.push_back (i);

		int min = 1000000;
			
			
		do
		{
			int sum = 0;
			for (int i = 0; i < n ; i++)
				sum += matrix[i][vec[i]];
			
			if (sum < min)
				min = sum;


		}while ( next_permutation(vec.begin() , vec.end()));


		cout << min << endl;
	}
	return 0;
}