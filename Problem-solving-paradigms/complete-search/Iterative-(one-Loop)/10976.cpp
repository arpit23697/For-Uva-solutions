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
	int k;
	while (scanf ("%d",&k) != EOF)
	{
		long long int ans[100000][2];
		long long int y , x;
		long long int counter = 0;
		for (y = k+1 ; y <= 2*k ; y++)
		{
			if ((k*y) % (y - k) == 0)
			{
				x = (k*y) / (y - k);
				ans[counter][0] = x;
				ans[counter][1] = y;
				counter++;
			}
		} 

		cout << counter << endl;
		for (long long int i =0 ; i < counter ; i++)
			cout << "1/" << k << " = 1/" << ans[i][0] << " + 1/" << ans[i][1] << endl;
	}

	return 0;
}