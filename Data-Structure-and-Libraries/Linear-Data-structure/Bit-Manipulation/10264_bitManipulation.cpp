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
	int n;
	while (scanf("%d" ,&n) == 1)
	{
		long long int number_of_corners = pow (2 , n);
		int weights[number_of_corners];
		int sum[number_of_corners];

		for (long long int i =0 ; i < number_of_corners ; i++)
			scanf("%d", &weights[i]);


		//assigning the weights
		for (int i =0 ; i < number_of_corners ; i++)
		{
			int sumOfWieghts = 0;
			for (int j =0 ; j < n ; j++)
			{
				long long int temp = i ^ (1 << j);
				sumOfWieghts += weights[temp];

			}
			sum[i] = sumOfWieghts;
		}

		int ans = 0;
		for (int i =0 ; i < number_of_corners ; i++)
		{
			for (int j =0 ; j < n ; j++)
			{
				long long int temp = i ^ (1 << j);
				ans = max (ans , sum[i] + sum[temp]);

			}
		}

		cout << ans << endl;
	}

	return 0;
}