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

int distance (int i , int j , int a)
{
	return (abs(a/5-i) + abs(a%5-j));
}

int main ()
{
	int test;
	cin >> test;

	while (test--)
	{
		int queries;
		cin >> queries;

		int information[5][5];
		memset (information , 0 , sizeof information);

		for (int i =0 ; i < queries ; i++)
		{
			int a , b , c;
			cin >> a >>b >> c;
			information[a][b] = c;
		}


		vector <int> ans;
		long long int min = INT_MAX;


		for (int a = 0; a < 25 ; a++)
			for (int b = a+1 ; b < 25 ; b++)
				for (int c = b+1 ; c < 25 ; c++)
					for (int d = c+1 ; d < 25 ; d++)
						for (int e = d+1 ; e < 25 ; e++)
						{
							long long int temp = 0;
							for (int i = 0 ; i < 5 ;i++)
								for (int j = 0 ; j< 5 ; j++)
								{

									if (information[i][j] != 0)
									{
										vector <int> local;
										int localMin ;

										local.push_back (distance (i , j , a));
										local.push_back (distance (i , j , b));
										local.push_back (distance (i , j , c));								
										local.push_back (distance (i , j , d));
										local.push_back (distance (i , j , e));


										localMin = *(min_element (local.begin() , local.end()));

										temp += localMin * information[i][j];

									}
								}


							if (temp < min)
							{
								ans.clear();
								//cout << " " << temp << " " << min << endl;
								ans.push_back(a);
								ans.push_back(b);
								ans.push_back(c);
								ans.push_back(d);
								ans.push_back(e);
								min = temp;
							}	
						}


		for (int i = 0 ; i < 5 ; i++)
		{
			if (i < 4)
				cout << ans[i] << " ";
			else
				cout << ans[i] << endl;
		}

	}

	return 0;
}