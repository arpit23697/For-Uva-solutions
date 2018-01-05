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

bool comparator (pair <double , double> &p1 , pair <double , double > &p2)
{	
	return p1.first < p2.first;
}

int main ()
{

	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);
	long long int n , length , width;

	int cases = 0;
	while (scanf("%lld %lld %lld" ,&n , &length , &width) == 3)
	{	
		
		vector <pair <double , double>> circles;
		for (int i = 0 ; i < n ; i++)
		{
			long long int radius , pos;
			cin >> pos >> radius;
			
		
			if (2*radius >= width)
			{	
				double interval;
				interval = sqrt (radius * radius - (width/2.0) * (width/2.0));
				circles.push_back (make_pair ((pos*1.0 - interval) , (pos*1.0 + interval)));	
			}
		}

		sort (circles.begin () , circles.end() , comparator);

		
		double rLimit = 0;
		int sprinklers = 0;

		while (rLimit < length)
		{
			double currentLevel = rLimit;
			bool flag = false;
			double tempLevel = rLimit;

			for (long long int i =0 ; i < circles.size() ; i++)
			{
				if (circles[i].first > currentLevel)
					break;

					if (circles[i].second > tempLevel )
					{
						flag = true;
						tempLevel = circles[i].second;

					}
			}

	

			if (flag == false)
				break;

			sprinklers++;
			rLimit = tempLevel;
		}
		if (rLimit >= length)
			cout << sprinklers << endl;
		else
			cout << "-1" << endl;

	}

	fclose (stdin);
	fclose (stdout);
	return 0;
}