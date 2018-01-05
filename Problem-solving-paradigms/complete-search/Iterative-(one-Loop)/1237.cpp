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

	for (int m =0 ; m < test ; m++)
	{
		int n;
		cin >> n;

		int L[n] , H[n] ;
		string cars[n];

		for (int i =0; i < n ; i++)
			cin >> cars[i] >> L[i] >> H[i];

		int queries;
		cin >> queries;
		for (int i =0 ; i < queries ; i++)
		{
			int price;
			cin >> price;

			int counter = 0;
			string ans;
			for (int j =0 ; j < n ; j++)
			{
				if (price >= L[j] && price <= H[j])
				{
					ans = cars[j];
					counter++;
				}

				if (counter >= 2)
					break;
			}


			if (counter != 1)
				cout << "UNDETERMINED" << endl;
			else
				cout << ans << endl;

		}
		if (m < test -1)
			cout << endl;
	}

	return 0;
}