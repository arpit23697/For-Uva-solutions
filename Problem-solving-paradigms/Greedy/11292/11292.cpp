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
		long long int d , k;
		cin >> d >> k;

		if (d == 0 && k == 0)
			break;

		long long int dragon[d] , knight[k];
		for (int i =0 ; i < d ; i++)
			cin >> dragon[i];

		for (int i =0 ; i < k ; i++)
			cin >> knight[i];

		sort (dragon , dragon + d);
		sort (knight , knight + k);

		long long int i =0 , j = 0;
		long long int gold = 0;
		while (i < d || j < k)
		{
			while (j < k && dragon[i] > knight[j])j++;
			if (j == k)
				break;

			gold += knight[j];
			j++ ;
			i++;
		}

		if (i != d)
			cout << "Loowater is doomed!" << endl;
		else
			cout << gold << endl;
	}


	fclose (stdin);
	fclose (stdout);
	return 0;
}