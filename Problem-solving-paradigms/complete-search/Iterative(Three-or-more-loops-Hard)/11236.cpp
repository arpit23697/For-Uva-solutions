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
	for (long long int p1 = 1 ; p1 <= 2000 ; p1++)
	{
		if (pow (p1 , 4) > 2 * pow (10 , 9))
			break;
		for (long long int p2 = p1 ; p2 <= 2000-p1 ; p2++)
		{	
			if (p1 * pow (p2 , 3) > 2 * pow (10 , 9))
				break;
			for (long long int p3 = p2 ; p3 <= 2000 - p1 - p2 ; p3++ )
			{
				if (p1 * p2 * pow (p3 , 2) > 2 * pow (10 , 9))
					break;
			
				long long int b = p1 * p2 * p3;
				long long int c = 1000000;

				if (b == c)
					continue;

				long long int a = p1 + p2 + p3;
				long long int d = c*a;
				long long int e = b - c;

				if (d % e != 0)
					continue;

				long long int p4 = d/e;
				if (p3 > p4)
					continue;

				if (a + p4 > 2000)
					continue;
				if (b * p4 > 2 * pow (10 , 9))
				continue;

				printf ("%.2lf %.2lf %.2lf %.2lf\n",p1/100.0 , p2/100.0 , p3/100.0 , p4/100.0); 
			}


		}

	}

	return 0;
} 