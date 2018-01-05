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

double solve (int p , int q , int r , int s , int t , double x)
{
	return ( p * exp (-x) + q * sin (x) + r * cos (x) + s * tan(x) + t * x *x);
}

int main ()
{
	//freopen ("1.txt" , "r" , stdin);
	//freopen ("ans.txt" , "w" , stdout);
	int p , q , r , s , t , u;
	while (scanf ("%d %d %d %d %d %d",&p , &q , &r , &s , &t , &u) == 6)
	{
		double x;
	
		double lower = 0;
		double upper = 1;
		bool solution = true;
		while (1) 
		{

			
			x = (lower + upper)/2;
			
			if (lower >= upper)
			{
				solution = false;
				break;
			}


			double ans = solve (p , q , r , s , t , x);
			//cout << lower << " " << upper << " " << x << " " << ans << endl; 
			if (ans >= -u - 0.00000001 && ans <= -u + 0.00000001 )
				break;

			else if (ans >= -u)
				lower = x;

			else
				upper = x ;
		}

		//x = round (x * 10000.0) / 10000.0;

		if (solution)
		printf ("%.4lf\n",x);
		else 
		cout << "No solution" <<endl;
	}

	//fclose (stdin);
	//fclose (stdout);

	return 0;
}