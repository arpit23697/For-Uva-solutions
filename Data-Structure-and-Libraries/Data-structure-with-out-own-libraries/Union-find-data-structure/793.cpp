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
				p[i] = i;
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

		void unionSet (int i , int j)
		{
			if (!isSameSet (i , j))
			{
				int x = findSet(i);
				int y = findSet(j);

				if (rank[x] < rank[y])
					p[x] = y;
				else
					p[y] = x;

				if (rank[x] == rank[y])
					rank[x]++;
			}
		}

		int numOfDisjointSets ()
		{
			int ans = 0;
			for (int i =0 ; i < p.size() ; i++)
				if (p[i] == i)
					ans++;

			return ans;
		}

		int sizeOfSet (int i)
		{
			int ans =0;
			int x = findSet(i);

			for (int i =0 ; i < p.size() ; i++)
				if (findSet(i) == x)
					ans++;

			return ans;
		}
};

int main ()
{
	int test;
	
	scanf ("%d",&test);



	for (int m =0 ; m < test ; m++)
	{
		int successful = 0;
		int unSuccessful = 0;
		int N;
		
		scanf ("\n%d\n",&N);


		unionFind obj1(N);

		string str;
		while (true)
		{

			if (!getline (cin , str) || str.empty())
				break;

			
			int x , y;
			char c;
			sscanf (str.c_str()," %c %d %d ",&c,&x,&y);

			if (c == 'c')
				obj1.unionSet (x-1 , y-1);

			else if (c == 'q')
			{
				if (obj1.findSet (x-1) == obj1.findSet(y-1))
					successful++;
				else
					unSuccessful++;
			}

		}
	

		cout << successful << "," << unSuccessful <<endl;
		if (m < test-1)
			cout << endl;
	}

	return 0;
}
