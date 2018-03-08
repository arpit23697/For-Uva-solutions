
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
long long int money , n , m[100000] , favour[100000] , memo[110][15000] ;
long long int val (long long int id , long long int soFar)
{ 
	if (soFar > money && money < 1800)
		return -1000;
	if (soFar > money + 200)
		return -1000;
	if ( id == n )
	{
		if (soFar > money && soFar <= 2000)
			return -1000;
		return 0;
	}

	//cout << id << " " << soFar << endl;
	if (memo[id][soFar] != -1)
		return memo[id][soFar];

	return memo[id][soFar] =  max ( val (id + 1 , soFar) , favour[id] + val(id +1 , soFar + m[id]) );
}


int main ()
{
	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);

	while (scanf ("%lld %lld",&money , &n ) == 2)
	{
		for (int i = 0 ; i < n ; i++)
			cin >> m[i] >> favour[i];

		memset (memo , -1 , sizeof memo);


		long long int ans = val ( 0, 0);
		cout << ans << endl;


	}

	fclose (stdin);
	fclose (stdout);
	return 0;
}