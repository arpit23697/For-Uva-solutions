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
	int army , attacks;
	while (1)
	{
		cin >> army >> attacks ;
		if (army == 0 && attacks == 0)
			return 0;

		int left[1000005] , right[1000005];
		for (int i =1 ; i <= army ; i++)
		{
			left[i] = i-1;
			right[i] = i+1; 
		}

		while (attacks--)
		{
			int l ;
			int r;

			cin >> l >> r;

			if (left[l] > 0)
				cout << left[l] << " ";
			else 
				cout << "* ";

			if (right[r] <	 army+1)
				cout << right[r] << endl;
			else
				cout << "*" << endl;
			if (left[l] > 0)
			right[left[l]] = right[r];
			if (right[r] <= army)
			left[right[r]] = left[l];
		}
		cout << "-" << endl;
	}

	return 0;
}