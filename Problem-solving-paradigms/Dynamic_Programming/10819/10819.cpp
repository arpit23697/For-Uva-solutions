
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
long long int money , n , values[100000] , wt[100000] , totalExpense;
long long int val (long long int id , long long int remMoney)
{


	if (remMoney <= 0)
		return 0;
	else if (id == n)
		return 0;
	else if (values[id] > remMoney )
		return val (id + 1 , remMoney);
	else
	{
		long long int x1 = val (id+1 , remMoney) ;
		long long int x2 = wt[id] + val(id + 1 , remMoney - values[id]);
		return max (x1 , x2);
	}
}


int main ()
{
	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);

	while (scanf ("%lld %lld",&money , &n ) == 2)
	{
		totalExpense = 0;
		for (int i = 0 ; i < n ; i++)
			cin >> values[i] >> wt[i];

		long long int ans = val ( 0, money);
		cout << ans << endl;

	}

	fclose (stdin);
	fclose (stdout);
	return 0;
}