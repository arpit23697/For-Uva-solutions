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

bool check (vector <int> vec , int n)
{
	for (int i =0 ; i < n ; i++)
		if (vec[i] != i+1)
			return false;

	return true;
}

int main ()
{
	int n;
	while (scanf("%d",&n) == 1)
	{
		int a[n];

		for (int i = 0 ; i < n ; i++)
			cin >> a[i];

		vector <int> vec;
		for (int i =0 ; i < n-1 ; i++)
			vec.push_back(abs (a[i+1] - a[i]));
	
		sort (vec.begin () , vec.end());
		//for (int i =0 ; i < n-1 ; i++)
		//	cout << vec[i] << "  ";

		//cout << endl;

		if (check(vec, n-1))
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
	}

	return 0;
}