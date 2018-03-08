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
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);

    long long int test;
    cin >> test;
    for (int m = 0 ; m < test ; m++)
    {
    	
    	long long int stops;
    	cin >> stops;

    	long long int n = stops - 1;
    	long long int A[n+100];
    	for (int i = 0 ; i < n ; i++)
    		cin >> A[i];

    	long long int start = 0;
    	long long int end = 0;

    	long long int ans = 0;
    	long long int sum = 0;

    	long long int x = -1, y =-1 ;
    	for (long long int i = 0 ; i < n ; i++)
    	{
    		sum += A[i];
    			y++;
    		
    		if (ans > sum)
    			ans = ans;
    		else if (sum > ans)
    		{
    			ans = sum;

    			start = x+1;
    			end = y+1;
    		}
    		else
    		{
    			if (y - x > end - start)
    			{
    				start = x+1;
    				end = y+1;
    			}
    		}

    		if (sum < 0)
    		{
    			sum = 0;
    			x = i;
    			y = i;
    		}
    	}

    	if (end == 0 && start == 0)
    		printf("Route %d has no nice parts\n",m+1);
    	else
    		printf ("The nicest part of route %d is between stops %lld and %lld\n" ,m+1 , start+1 , end+1 );
    	

    }
  	
    fclose (stdin);
    fclose (stdout);

    return 0;
}