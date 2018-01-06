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

	int cases = 0;
	while (1)
	{
		cases++;
		int n,m;
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		vector <int> men;
		men.assign(n , 0);

		vector <int> women;
		women.assign (m , 0);

		for (int i =0 ; i < n ; i++)
			cin >> men[i];

		for (int i = 0; i < m ; i++)
			cin >> women[i];

		cout << "Case " << cases << ":";
		if (n > m)
			cout << " " << (n - m) << " " << *(min_element(men.begin() , men.end())) << endl;
		else
			cout << " 0" << endl;

	}	

	fclose (stdin);
	fclose (stdout);
	return 0;
}