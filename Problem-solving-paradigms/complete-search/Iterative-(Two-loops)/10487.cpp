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

# define MAX 1000000 

int main ()
{
	int cases = 0;
	while (1)
	{
		cases++;
		long long int n;
		cin >> n;

		if (n == 0)
			break;

		long long int a[n];
		for (int i =0 ; i < n ; i++)
			cin >> a[i];

		long long int queury;
		cin >> queury;

		cout << "Case " << cases << ":" << endl;
		for (int i = 0; i < queury ; i++)
		{
			int value;
			cin >> value;

			long long int min = INT_MAX;
			long long int ans ;

			for (int j =0 ; j < n ; j++)
			{	
				for (int i = j+1 ; i < n ; i++)
				{
					if (abs(a[i] + a[j] - value) < min)
					{
						ans = a[i]+a[j];
						min = abs (a[i] + a[j] - value);
					}
				}					
			}	

			cout << "Closest sum to " << value << " is " << ans << "." << endl;

		}
	}

	return 0;
}