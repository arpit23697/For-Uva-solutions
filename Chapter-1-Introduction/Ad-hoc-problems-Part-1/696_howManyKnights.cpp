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
	while (1)
	{
		int rows , cols;

		cin >> rows >> cols;
		if (rows == 0 && cols == 0)
			return 0;

		int ans =0;
		if (min (rows , cols) == 1)
		{
			ans = max(rows , cols);
		}

		else if (min (rows , cols ) == 2)
		{
			int a[2][max (rows , cols)];
			for (int i =0 ; i < 2 ; i++)
				for (int j  =0 ; j < max (rows , cols) ; j++)
				{
					if (i%4 <= 1 && j % 4 <= 1  )
						ans += 1;
				}
		}

		else 
		{
			ans = rows* cols/2;
			if ((rows*cols )%2 != 0)
				ans += 1;
		}

		cout << ans << " knights may be placed on a " << rows << " row " << cols << " column board." << endl;

	}

	return 0;
}