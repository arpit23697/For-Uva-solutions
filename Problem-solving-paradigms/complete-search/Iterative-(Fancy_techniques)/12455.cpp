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

		int p;
		cin >> p;
		int a[p];
		for (int i =0 ; i < p ; i++)
			cin >> a[i];


		bool sol = false;
		for (int i =0 ; i < (1 << p) && !sol ; i++)
		{
			int sum = 0;
			for (int j = 0 ; j < p ; j++)
				if (i & (1 << j))
					sum += a[j];

			if (sum == n)
			{
				sol = true;
				break;
			}
		}

		if (sol == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}