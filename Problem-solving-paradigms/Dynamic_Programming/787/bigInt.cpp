//this code is working 

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

class Big 
{
	public :
		vector <int> c;
		bool sign;

	public :
		Big (int v)
		{
			set (v);
		}

		Big (const Big &a)
		{
			c = a.c;
			sign = a.sign;
		}

		void set (int v)
		{
			if (v < 0) sign = true;		//sign is true when the sign is negative
			else	sign = false;
			c.clear ();
			c.push_back (abs(v));
		}

		bool operator < (const Big &a) const
		{
			if (sign != a.sign)
				return sign;

			if (c.size() != a.c.size())
			{
				if (c.size() < a.c.size())
					return true;
				else
					return false;
			}

			for (int i = c.size() - 1 ; i >= 0 ; i--)
			{
				if (c[i] != a.c[i])
				{
					if (c[i] < a.c[i])
						return true;
					else
						return false;
				}
			}

			return false;

		}

		void multiply (int a)
		{
			sign = (sign ^ (a < 0)) && (a != 0);
			a = abs(a);

			for (vector <int> :: iterator itr = c.begin () ; itr != c.end() ; ++itr)
			{
				(*itr) *= a;
			}

			for (int i = 0;  i < c.size() -1 ; i++)
			{
				c[i+1] += c[i]/1000;
				c[i] %= 1000;
			}

			while (c.back () >= 1000)
			{
				int t = c.back();
				c.back () = t % 1000;
				c.push_back (t / 1000);
			}
			while (c.size() > 1 && c.back() == 0)
				c.erase(c.end() - 1);
		}

		void print()
		{
			if (sign)putchar('-');
			printf("%d" , c.back());
			for (int i = c.size() - 2 ; i >= 0 ; i--)
			{
				printf ("%03d",c[i]);
			}
			cout << endl;
		}

};

int main ()
{

	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);
	long long int temp;
	long long int a[200];
	while (scanf ("%lld",&temp) == 1)
	{
		a[0] = temp;
		int i = 1;
		while (scanf ("%lld",&temp) == 1 && temp != -999999)
		{
			a[i] = temp;
			i++;
		}

		int n = i;
		Big mainAnswer (a[0]);
		Big product (1);
		for (int i = 0; i < n ; i++)
		{
			product.multiply(a[i]);
			mainAnswer = max (product , mainAnswer);

			if (a[i] == 0)
				product.set(1);
		}

		product.set(1);
		for (int i = n -1 ; i >=0 ; i--)
		{
			product.multiply(a[i]);
			mainAnswer = max (product , mainAnswer);

			if (a[i] == 0)
				product.set(1);
		}

		mainAnswer.print();
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}