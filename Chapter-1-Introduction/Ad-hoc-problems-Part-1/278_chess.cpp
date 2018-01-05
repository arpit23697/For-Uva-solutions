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
	cin >> test ;

	while (test--)
	{
		int rows , cols ;
		char piece ;

		cin >> piece >> rows >> cols;

		int ans = 0;
		if (piece == 'r')
			ans = min (rows , cols);

		else if (piece == 'k')
		{
			ans = rows* cols/2;
			if ((rows*cols )%2 != 0)
				ans += 1;

		}

		else if (piece == 'Q')
			ans = min(rows , cols);

		else if (piece == 'K')
			ans = ((rows+1)/2 )* ((cols+1)/2);

		cout << ans << endl;

	}

	return 0;
}