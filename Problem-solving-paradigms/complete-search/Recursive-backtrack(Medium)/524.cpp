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

int n , a[20];
bool usedup[20];
pair <set <int > :: iterator , bool> pairs;

bool isprime (int n)
{
	for (int i = 2 ; i <= n/2 ; i++)
		if (n % i == 0)
			return false;

	return true;
}


void backtrack (int c)
{
	if (c == n)
	{
		if (isprime(a[0] + a[n-1]))
		{
			for (int i =0 ; i < n ; i++)
			{
				if (i < n-1)
					cout << a[i] << " ";
				else
					cout << a[i] << endl;
			}
		}
	}

	else
	{
		for (int i =1 ; i <= n ; i++)
		if (isprime(i + a[c-1]) && usedup[i] == false)
		{
				usedup[i] = true;
				a[c] = i;
				backtrack(c+1);
				usedup[i] = false;
		
		}
	}

}




int main ()
{

	cin >> n;
	int cases = 0;
	while (1)
	{	
		cases++;
		cout << "Case " << cases <<  ":" << endl;
		memset (a , -1 , sizeof a);
		memset (usedup , false , sizeof usedup);
		a[0] = 1;
		usedup[1] = true;
		backtrack (1);


		if (scanf ("%d",&n) != EOF)
			cout << endl;
		else
			break;
	}

	return 0;
}