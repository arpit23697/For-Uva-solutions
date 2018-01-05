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
	int s , c;
	int cases = 0;
	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);
	while (scanf("%d %d",&c,&s) == 2)
	{
		cases++;
		vector < pair <long long int , int > > a;
		long long int sum = 0;
		for (int i = 0 ; i < s ; i++)
		{	
			long long int temp;
			cin >> temp;
			sum += temp;
			a.push_back (make_pair (temp , i));
		}

		for (int i =s ; i < 2*c ; i++ )
			a.push_back (make_pair (0 , INT_MAX));


		sort (a.begin() , a.end());


		vector <tuple <int , long long int , long long int> > answer;
		answer.assign (c , make_tuple (-1 , -1 , -1));

		
		double A = sum * 1.0 / c;
		double imperfections = 0;

		for (int i = 0 ; i < c ; i++)
		{
			
			long long int ans1 , ans2;

			int indices1 = a[i].second;
			int indices2 = a[2*c - i - 1].second;
			
			if (indices1 < indices2)
			{	
				ans1 = a[i].first;
				ans2 = a[2*c - 1 - i].first;
			}
			else
			{
				ans2 = a[i].first;
				ans1 = a[2*c - 1 -i].first;
			}
			answer[i] = make_tuple (min (indices1 , indices2) , ans1 , ans2);

			imperfections += abs(A - ans1 - ans2); 
		} 

		sort (answer.begin() ,answer.end());

		cout << "Set #" << cases << endl;
		for (int i = 0 ; i < c ; i++)
		{
			cout << " " << i << ":";
			long long int ans1 , ans2;
			ans1 = get <1>(answer[i]);
			ans2 = get <2>(answer[i]);

			if (ans1 != 0 )
				cout << " " << ans1;
			if (ans2 != 0)
				cout << " " << ans2;
			cout << endl;

		}

		
		printf("IMBALANCE = %.5lf\n" , imperfections);
		cout << endl;
	}

	fclose (stdin);
	fclose (stdout);
	return 0;
}