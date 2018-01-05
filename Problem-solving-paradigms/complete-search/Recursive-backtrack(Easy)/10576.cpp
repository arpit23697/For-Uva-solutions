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
	int s , d;
	while (scanf ("%d %d",&s , &d) == 2)
	{
		int max = - 13 * d;
		for (int i =0 ; i < (1 << 12) ; i++)
		{
			int sum = 0;
			bool flag = true;
			int ans = 0;
			for (int j = 0 ; j < 5 ; j++)
			{
				if (i & (1 << j))
				{	
					sum += s;
					ans += s;
				}
				else
				{	
					sum -= d;
					ans -= d;
				}
			}

			for (int j = 5 ; j < 12 ; j++)
			{
				if (sum > 0)
				{
					flag = false;
					break;
					
				}

				if (i & (1 << (j - 5)))
					sum -= s;
				else
					sum += d; 

				if (i & (1 << j))
				{	
					sum += s;
					ans += s;
				}
				else
				{	
					sum -= d;
					ans -= d;
				}

			}
			if (sum > 0)
				flag = false;


			if (ans >= max && flag)
				max = ans;
				

		}

		if (max > 0)
			cout << max << endl;
		else
			cout << "Deficit" << endl;
	}

	return 0;
}