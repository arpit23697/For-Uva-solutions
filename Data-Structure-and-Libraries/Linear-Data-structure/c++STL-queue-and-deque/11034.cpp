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

using namespace std;

int main ()
{
	int test;
	cin >> test;
	cin.ignore(100 , '\n');
	while (test--)
	{
		double length;
		int cases;

		cin >> length >> cases;

		string str;

		queue <double> left;
		queue <double> right;

		for (int i = 0 ; i < cases ; i++)
		{
			double temp;
			cin >> temp >> str;

			if (str == "left")
				left.push (temp / 100.0);

			else if (str == "right" )
				right.push(temp / 100.0);
		}

		bool onLeft = true;
		long long int ans = 0;
		while (true)
		{
			if (left.empty() && right.empty())
				break;

			double temp = 0;
			if (onLeft)
			{
				ans++;
				while(!left.empty() && temp + left.front() <= length )
				{
					temp += left.front();
					left.pop();
				}
				onLeft = false;
			}
			else if (onLeft == false )
			{
				ans++;
				while (!right.empty() && temp + right.front() <= length)
				{
					temp += right.front();
					right.pop();
				}
				onLeft = true;
			}
		}

		cout << ans << endl;
	}
	return 0;
}