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
	while (1)
	{
		int rear , front;
		cin >> front;

		if (front == 0)
			break;
		cin >> rear;

		int f[front] , r[rear];

		for (int i = 0; i < front ; i++)
			cin >> f[i];

		for (int i =0 ; i < rear ; i++)
			cin >> r[i];

		vector <double> vec;

		for (int i =0 ; i < front ; i++)
			for (int j =0 ; j < rear ; j++)
				 vec.push_back (1.0 * r[j] / f[i]);

		sort (vec.begin() , vec.end());
		double max = 0;

		for (int i =1 ; i < vec.size() ; i++)
			if (vec[i] / vec[i-1] >= max)
				max = vec[i] / vec[i-1];

		printf ("%.2lf\n", max);
	}

	return 0;
}