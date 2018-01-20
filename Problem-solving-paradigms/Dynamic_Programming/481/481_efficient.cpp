//time limit exceeded

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
vector <long long int> LIS;

long long int binarySearch (long long int value , int high , int low)
{
	long long int mid = -1;
	long long int ans = -1;
	while (low <= high)
	{
		mid = (low + high)/2;
		if (value > LIS[mid])
		{
			ans = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	return ans;
}


int main ()
{
	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);

	long long int a[100000];
	long long int temp;
	long long int n = 0;
	while (scanf ("%lld",&temp) == 1)
	{
		a[n] = temp;
		n++;
	}

	LIS.clear();
	LIS.assign (n , INT_MIN);

	vector <long long int > indices;
	indices.assign(n , -1);

	long long int pre[n];
	memset (pre , -1 , sizeof (pre));

	long long int currentAns = 1;
	LIS[0] = a[0];
	indices[0] = 0;

	for (int i =1 ; i < n ; i++)
	{
		if (a[i] > LIS[currentAns - 1])
		{
			LIS[currentAns] = a[i];
			indices[currentAns] = i;
			pre[i] = indices[currentAns - 1];
			currentAns++;
		}
		else
		{
			long long int mid = binarySearch (a[i] , currentAns , 0);
			LIS[mid+1] = a[i];
			indices[mid+1] = i;
			pre[i] = indices[mid];	
		}
	}

	cout << currentAns << endl;
	cout << "-" <<endl;

	vector <long long int> ans;
	long long int index = indices[currentAns - 1];
	do
	{
		ans.push_back (a[index]);
		index = pre[index];
	}while (index != -1);

	for (int i = currentAns - 1; i >= 0 ; i--)
		cout << ans[i] << endl;


	fclose (stdin);
	fclose (stdout);

	return 0;
}