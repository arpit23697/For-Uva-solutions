//time limit exceeded

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
	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);

	long long int a[100000];
	long long int temp;
	long long int n = 0;
	while (scanf ("%lld",&temp) == 1)
	{
		a[n] = temp;
		n++;
	}

	long long int LIS[n];
	long long int backtrack[n];

	for (int i = 0 ; i < n ; i++)
	{	
		LIS[i] = 1;
		backtrack[i] = -1;
	}
	for (int i = 1; i < n ; i++)
	{
		long long int temp = 0;
		long long int index = -1;
		for (int j = 0 ; j < i ; j++)
		{
			if (a[j] < a[i])
			{	
				if (temp <= LIS[j])
				{
					index = j;
					temp = LIS[j];
				}
			}
		}
		LIS[i] = temp + 1;
		backtrack[i] = index;
	}

	long long int ans = 0;
	long long int index = -1;
	for (int i = 0 ; i < n ; i++)
	{
		if (ans <= LIS[i] )
		{
			ans = LIS[i];
			index = i;
		}
	}
	
	cout << ans << endl;
	cout << "-" << endl;

	vector <long long int > vec;
	do
	{
		vec.push_back (a[index]);
		index = backtrack[index];

	}while (index != -1);

	for (vector <long long int> :: reverse_iterator itr = vec.rbegin() ; itr != vec.rend() ; ++itr )
		cout << *itr <<endl;

	fclose (stdin);
	fclose (stdout);
	return 0;
}