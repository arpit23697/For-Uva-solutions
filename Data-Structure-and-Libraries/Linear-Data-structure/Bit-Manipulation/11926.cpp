//this program is important

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
		int start[1000100];
		int end[1000100];

		long long int counter = 0;
		int n , m;

		cin >> n >> m;

		if (n == 0 && m == 0)
			return 0;

		for (int i =0 ; i < n ; i++)
		{
			cin >> start[counter] >> end[counter];
			counter ++;
		}

		for (int i =0 ; i < m ; i++)
		{
			long long int a , b , interval;
			cin >> a >> b >> interval;

			while (a <= 1000000 )
			{
				start[counter] = a;
				end[counter] = b;

				counter++;
				a += interval;
				b += interval;
			}
		}

		sort (start , start + counter);
		sort (end , end + counter);

	//	for (int i =0 ; i < counter ; i++)
	//		cout << start[i] << "  " << end[i] << endl;

		bool conflict = false;
		for (int i =1 ; i < counter ; i++)
		{
			if (start[i] < end[i-1])
			{
				conflict = true;
				break;
			}
		}

		if (conflict == true)
			cout << "CONFLICT" << endl;
		else
			cout << "NO CONFLICT" << endl;


	}

	return 0;
}