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

using namespace std;

int main ()
{
	int test;
	cin >> test;
	while (test--)
	{
		long long int sum , difference;
		cin >> sum >> difference;



		long long int a , b;
		a = (sum + difference)/2;
		b = (sum - difference)/2;


		if (a >= 0 & b >= 0 && a+b == sum && max (a,b) - min (a , b) == difference)
			cout << max(a , b) << " " << min (a , b) << endl;

		else
			cout << "impossible" << endl;
	}

	return 0;
}