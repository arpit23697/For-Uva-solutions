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


using namespace std;

int main ()
{
	while (1)
	{
		long long int n;
		cin >> n;

		if (n == 0)
			break;

		long long int ans =0 ;
		multiset <long long int> mySet;

		while (n--)
		{
			long long int k;
			cin >> k;

			for (int i = 0; i < k ; i++)
			{
				long long int temp;
				cin >> temp;
				mySet.insert(temp);
			}

			multiset <long long int> :: iterator itr1 = mySet.begin();
			multiset <long long int> :: iterator itr2 = mySet.end();

			itr2--;
			ans += (*itr2) - (*itr1);
			mySet.erase (itr1);
			mySet.erase (itr2);
		}

		cout << ans << endl;
	}

	return 0;
}