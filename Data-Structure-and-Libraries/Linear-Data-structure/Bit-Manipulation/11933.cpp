//this program is important

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

using namespace std;

int main ()
{
	while(1)
	{
		long long int n;
		cin >> n;

		if (n ==0)
			return 0;

		bitset <33> set1(n);
		bitset <33> ans1;
		bitset <33> ans2;

		bool flag = true;
		for (int i = 0 ; i < set1.size() ; i++)
		{
			if (set1[i] == 1)
			{
				if (flag == true)
				{
					ans1.set(i);
					flag = false;
				}
				else
				{
					ans2.set(i);
					flag = true;
				}

			}
		}

		cout << ans1.to_ulong() << " " << ans2.to_ulong() << endl;
		
	}

	return 0;
}