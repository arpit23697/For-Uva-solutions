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
	cin >> k;
	while (1)
	{
	

		if (k == 0)
			break;

		int a[k];
		for (int i =0; i < k ; i++)
			cin >> a[i];

		for (int an = 0 ; an < k ; an++)
			for (int b = an+1 ; b < k ; b++)
				for (int c = b+1 ; c < k ; c++)
					for (int d = c+1 ; d < k ; d++)
						for (int e = d+1 ; e < k ; e++)
							for (int f = e+1 ; f < k ; f++)
								cout << a[an] << " " << a[b] << " " << a[c] << " " << a[d] << " " << a[e] << " " << a[f] << endl;
	
		
		cin >> k;
		if (k == 0)
			break;
		else
			cout << endl;
	}


	return 0;
}