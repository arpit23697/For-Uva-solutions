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
		long long int n , d , r;
		cin >> n >> d >> r;

		if (n == 0 && d == 0 && r == 0)
			break;

		long long int morning[n] , evening[n];
		for (int i =0 ; i < n ; i++)
			cin >> morning[i];

		for (int i =0 ; i < n ; i++)
			cin >> evening[i];

		sort (morning , morning + n);
		sort (evening , evening + n , greater <int> ());

		long long int ans = 0;
		for (int i =0 ; i < n ; i++)
		{
			long long int temp = morning[i] + evening[i];
			if (temp > d)
				ans += (temp - d);
		}

		cout << ans * r << endl;
 	}
 	fclose (stdin);
 	fclose (stdout);
 	return 0;
}