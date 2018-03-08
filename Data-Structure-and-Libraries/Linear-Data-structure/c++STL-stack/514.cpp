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
using namespace std;

int main ()
{
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;

		while (1)
		{
			int current = 1;
			int a[n];
			stack <int> check;
			for (int i =0 ; i < n ; i++)
			{
				cin >> a[i];
				if (a[0] == 0)
					break;	
			}
			if (a[0] == 0)
				break;
		
			int counter =0 ;

			for (int i =1 ; i <= n ; i++)
			{
				check.push(i);

				while (check.size() > 0 && a[counter] == check.top())
				{
					check.pop();
					counter++;
				}
			}

			if (check.size() == 0)
				cout << "Yes" <<endl;
			else
				cout << "No" << endl;
		}

		cout << endl;
	}

	return 0;
}