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

class unionFind 
{
	private:
		vector <int> p ;
		vector <int> rank;

	public:
		unionFind (int n)
		{
			p.assign (n , 0);
			rank.assign(n , 0);
			for (int i =0 ; i < n ; i++)
			{	
				p[i] = i;
				rank[i] = 1;
			}
		}

		int findSet (int i)
		{
			if (p[i] != i)
				return findSet (p[i]);
			
				return i;
		}

		bool isSameSet (int i , int j)
		{
			return findSet(i) == findSet(j);
		}

		int unionSet (int i , int j)
		{
			int x = findSet(i);
			int y = findSet(j);
			if (!isSameSet (i , j))
			{
				
				if (rank[x] < rank[y])
				{
					p[x] = y;
					rank[y] += rank[x];
					return rank[y]; 
				}
				else
				{
					p[y] = x;
					rank[x] += rank[y];
					return rank[x];
				}
			}
			return rank[x];
		}

		int numOfDisjointSets ()
		{
			int ans = 0;
			for (int i =0 ; i < p.size() ; i++)
				if (p[i] == i)
					ans++;

			return ans;
		}

		int sizeOfSet (int i , int limit)
		{
			int ans =0;
			int x = findSet(i);

			for (int i =0 ; i < limit ; i++)
				if (findSet(i) == x)
					ans++;

			return ans;
		}
};

int main ()
{
	int test;
	cin >> test;
	while (test--)
	{
		
		map <string , int> myMap;

		int x = 0;
		int friendShip;
		cin >> friendShip;

		unionFind obj1(min (2*friendShip , 100000));
		while (friendShip--)
		{
			string f1;
			string f2;

			cin >> f1 >> f2;
			

			pair  <map <string , int > :: iterator , bool > pair_Retrieve;  
			pair_Retrieve = myMap.insert (make_pair ( f1 , x));
			
			if (pair_Retrieve.second == true)
				x++;

			pair_Retrieve =  myMap.insert (make_pair ( f2 , x));

			if (pair_Retrieve.second == true)
				x++;

			
			cout << obj1.unionSet (myMap[f1] , myMap[f2]) << endl;

		}
	}

	return 0;
}