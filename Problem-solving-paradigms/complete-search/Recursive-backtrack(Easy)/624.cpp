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
	int length;
	while (scanf ("%d" , &length) != EOF)
	{
		int n;
		cin >> n;
		int a[n];

		for (int i = 0; i < n ; i++)
			cin >> a[i];

		int min = length+1;
		int ans;

		bool flag = false;

		for (int i =0 ; i < (1 << n) ; i++)
		{
			int sum = 0;
			for (int j = 0 ; j < n ; j++)
			{
				if (i & (1 << j))
					sum += a[j];
			}

			if (sum <= length)
			{
				if (flag == false)
				{
					ans = i;
					min = length - sum;
					flag = true;
				}
				bitset <21> set1(i);
				bitset <21> set2(ans);
				if (length - sum < min || (length - sum == min ) && set1.count() > set2.count() ) 
				{
					min = length - sum;
					ans = i;
				}
			}
		}


		for (int i = 0 ; i < n ; i++)
			if (ans & (1 << i))
				cout << a[i] << " ";

		cout << "sum:" << length - min << endl;
	}

	return 0;
}