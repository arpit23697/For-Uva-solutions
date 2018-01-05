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
	int m;
	while (scanf ("%d",&m) != EOF)
	{
		int ans = 0;
		int a[m][m];
		string str;
		for (int i = 0 ; i < m ; i++)
		{
			cin >> str;
			for (int j = 0; j < m ; j++)
				a[i][j] = str[j] - '0';
		}

			for (int i = 0 ; i < m ; i++)
				for (int j = 0; j < m ; j++)
				{
					
					if (a[i][j] == 1)
					{
						int min = INT_MAX;
						for (int k = 0 ; k < m ; k++)
							for (int l = 0 ; l < m ; l++)
								if (a[k][l] == 3 && min >= abs (k-i) + abs (l-j))
									min = abs (k-i) + abs (l-j);

					
						if (ans <= min)
						ans = min;
					}

					
				}
		

		cout << ans << endl;


	}

	return 0;
}