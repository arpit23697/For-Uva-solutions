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
	while (true)
	{
		long long int m , n;
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		long long int ans = 0;

		set <long long int> mySet;
		for (long long int i =0 ; i < n ; i++)
		{
			long long int temp;
			cin >> temp;
			mySet.insert(temp);
		}

		for (long long int i =0 ; i < m ; i++)
		{
			long long int temp;
			cin >> temp;
			if (mySet.find(temp) != mySet.end())
				ans++;
		}

		cout << ans << endl;

	}
	return 0;
}