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
	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);

	while (1)
	{
		int n;
		cin >> n;

		if (n == 0)
			break;

		int temp;
		bool allZero = true;
		bool first = true;

		for (int i =0 ; i < n ; i++)
		{
			cin >> temp;
			if (temp != 0)
			{
				if (first)
					cout << temp;
				else
					cout << " " << temp;

				first = false;
				allZero = false;
			}
		}
		if (allZero)
			cout << "0" << endl;
		else
			cout << endl;
	}

	fclose (stdin);
	fclose (stdout);
	return 0;
}