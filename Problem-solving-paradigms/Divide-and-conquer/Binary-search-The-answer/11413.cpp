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
int a[1100];
int n , m;

bool tryCapacity (int maxCap)
//this function returns true if the problem conditions are satisfied else false
{
	int total = 0;
	int cur = 0;

	for (int i =0 ; i < n ; i++)
	{	
		if (a[i] > maxCap) return false;
		if (cur + a[i] > maxCap) cur = 0;
		if (cur == 0) total++;

		cur += a[i];

		if (total > m)
			return false;
	}	
	return true;

}


int main ()
{
	freopen ("1.txt" , "r" , stdin);
	freopen ("ans.txt" , "w" , stdout);
	while (scanf ("%d %d",&n , &m) == 2)
	{
		long long int sum = 0;
		for (int i = 0; i < n ; i++)
		{	
			cin >> a[i];
			sum += a[i];
		}

		long long int low = 1;
		long long int high = 1000000000;

		long long int ans ;
		long long int actualAns = sum ;
		while (1)
		{
			ans = (low + high)/2;
			//cout << low << " " << high << endl;
			if (low > high)
				break;

			
			if (tryCapacity (ans))
			{	
				high = ans-1;
				actualAns = ans;
			}
			else
				low = ans+1;
		}

		cout << actualAns << endl;
	}


	fclose (stdin);
	fclose (stdout);

	return 0;
}