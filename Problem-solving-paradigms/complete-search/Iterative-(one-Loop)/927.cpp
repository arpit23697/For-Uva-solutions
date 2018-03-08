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
		int degree;
		cin >> degree;

		int a[degree+1];
		for (int i =0 ; i <= degree ; i++)
			cin >> a[i];

		int d;
		int k;
		cin >> d >> k;
		int value = 0;
		int i;
		for ( i =1 ; i <= k ; i++)
		{
			value += i*d;
			if (value  >= k)
				break;
			
		}


		long long int ans = 0;
		for (int j =0 ; j < degree+1 ; j++)
			ans += a[j] * pow ( i , j) ;
		
			



		cout << ans << endl;
	}

	return 0;
}