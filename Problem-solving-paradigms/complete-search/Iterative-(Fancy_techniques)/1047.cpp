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

bool compare (vector<int> &vec1 , vector <int> &vec2)
{
	for (int i = 0 ; i < vec1.size() ; i++)
		if (vec1[i] < vec2[i])
			return true;

	return false;
}


int main ()
{

	int n , m;

	int cases = 0;
	while (1)
	{
		cases++;
		
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		int a[n];
		for (int i =0 ; i < n  ; i++)
			cin >> a[i];

		int queries;
		cin >> queries;

		vector < vector <int> > vec;
		vec.assign (queries , vector <int> ());

		for (int i = 0; i < queries ; i++)
		{
			int temp;
			cin >> temp;
			
			for (int j = 0 ; j <= temp ; j++)
			{
				int value;
				cin >> value;
				vec[i].push_back(value);
			}
		}


		vector <int> ans;
		ans.assign (m , n);

		int max = 0;

		vector <int> combinations;
		for (int i = (1 << m)-1 ; i < (1 << n) ; i++ )
		{
			combinations.clear();
			bitset <20> set1(i);
			if (set1.count () != m)
				continue;
			
			for (int j = 0 ; j < n ; j++)
				if (i & (1 << j) )
					combinations.push_back (j+1);

			int sum = 0;
			for (int j = 0; j < m ; j++)
				sum += a[combinations[j]-1];
			for (int j = 0 ; j < queries ; j++)
			{

				int frequency=0;
				int size = vec[j].size();
				for (int k = 0 ; k < size-1 ; k++)
				{
			
					if (find (combinations.begin() , combinations.end() , vec[j][k]) != combinations.end())
					{
						frequency++;	
					}
				}
				if (frequency > 1)
				sum = sum - (frequency-1) * vec[j][size-1]; 
			}

			if ( (sum > max) || (sum == max && compare (combinations , ans) ))
			{
				ans.clear();
				copy ( combinations.begin() , combinations.end() , ans.begin());
				max = sum;
			}
		}
		printf("Case Number  %d\n", cases);
        printf("Number of Customers: %d\n", max);
        printf("Locations recommended:");

		for (int i =0 ; i < m ; i++)
		{
			cout << " " <<ans[i] ;
		}
		
		cout << endl;
		cout << endl;
	}
	return 0;
}
	
