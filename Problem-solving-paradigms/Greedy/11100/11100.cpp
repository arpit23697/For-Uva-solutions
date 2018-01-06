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

	long long int n;
	cin >> n;
	while (1)
	{
		long long int a[n];
		for (int i =0 ; i < n ; i++)
			cin >> a[i];
	
		sort (a , a+n);

		int k = -1;
		for (int i = 0 ; i < n ; i++ )
		{
			int temp = 0;
			int j;
			for ( j = i ; j < n ; j++)
			{
				if (a[j] != a[i])
					break;
				else
					temp++;
			}

			if (temp > k)
				k = temp;

			temp = 0;
			i = j-1;
		}

		cout << k << endl;


		for (int i = 0 ; i < k ; i++)
		{
			bool first = true;
			for (int j = i ; j < n ; j +=k )
			{
				if (first == true)
					first = false;
				else
					cout << " ";
				cout << a[j];
			}
			cout << endl;
		}
		
				
		cin >> n;
		if (n!= 0)
		cout << endl;
		else
			break;
	}
	

	fclose (stdin);
	fclose (stdout);
	return 0;
}