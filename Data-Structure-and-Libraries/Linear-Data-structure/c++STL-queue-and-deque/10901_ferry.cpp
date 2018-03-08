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

using namespace std;
#define MAX 10000000

int main ()
{
	int test;
	cin >> test;

	for (int m = 0 ; m < test ; m++)
	{
		int n , t , cases;
		cin >> n >> t >> cases;

		string str;
		queue <pair <int , int >> left;
		queue <pair <int , int >> right;

		for (int i =0 ; i < cases ; i++)
		{
			int temp;
			cin >> temp >> str;
			
			if (str == "left")
				left.push(make_pair (i , temp));
			else if (str == "right")
				right.push(make_pair (i , temp));
		}


		int currentTime = 0;
		bool onLeft = true;

		vector < pair < int ,int>> ans;
		while (true)
		{
			;
			if (left.empty() && right.empty())
				break;


			int loaded = 0;
			if (onLeft == true)
			{
				
				while (!left.empty() && left.front().second <= currentTime && loaded < n )
				{
					ans.push_back(make_pair(left.front().first , currentTime+t)) ;
					left.pop();
					loaded++;

				}
				
				

				if (loaded == 0 )
				{	
					long long int a=MAX , b=MAX;
					if (!left.empty())
						a = left.front().second;

					if (!right.empty())
						b = right.front().second;

					if (b < currentTime)
					{
						currentTime += t;
						onLeft = false;
						continue;
					}
	

					else if (a <= b)
					{
						currentTime = a;
						onLeft = true;
						continue;
					}

					else if (a > b)
					{
						currentTime = b+t;
						onLeft = false;
						continue;
					}
				}
				currentTime += t;
				onLeft = false;
			}

			else if (onLeft == false)
			{
				while (!right.empty() && right.front().second <= currentTime && loaded < n )
				{
					
					ans.push_back(make_pair(right.front().first , currentTime+t)) ;
					right.pop();
					loaded++;

				}

				if (loaded == 0 )
				{	
					long long int a=MAX , b=MAX;
					if (!left.empty())
						a = left.front().second;

					if (!right.empty())
						b = right.front().second;

					if (a < currentTime)
					{
						currentTime += t;
						onLeft = true;
						continue;
					}

					else if (a <= b)
					{
						currentTime = a+t;
						onLeft = true;
						continue;
					}

					else if (a > b)
					{
						currentTime = b;
						onLeft = false;
						continue;
					}
				}
				currentTime += t;
				onLeft = true;
			}
		}

		sort (ans.begin() , ans.end());
		for (int i =0; i < ans.size() ; i++)
			cout << ans[i].second << endl;

		if (m < test-1)
			cout << endl;
	}

	return 0;
}