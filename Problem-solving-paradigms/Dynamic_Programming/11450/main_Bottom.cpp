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

    int test;
    cin >> test;
    while (test--)
    {
    	int M , C , price[25][25];
    	cin >> M >> C;

    	for (int i = 0 ; i < C ; i++)
    	{
    		cin >> price[i][0];
    		for (int j = 1 ; j <= price[i][0] ; j++ )
    			cin >> price [i][j];
    	}

    	bool reachable[20][201];
    	memset (reachable , false , sizeof reachable);

    	//for the base case
    	for (int model = 1 ; model <= price[0][0] ; model++)
    		if (M - price[0][model] >= 0)
    			reachable[0][M - price[0][model]] = true;

    	for (int g = 1 ; g < C ; g++)
    	{
    		for (int money = 0 ; money <= M ; money++)
    		{
    			if (reachable[g-1][money] == true)
    			{
    				for (int model = 1 ; model <= price[g][0] ; model++)
    				{
    					if (money - price[g][model] >= 0)
    						reachable[g][money - price[g][model]] = true;
    				}
    			}
    		}
    	}

    	int money;
    	for ( money = 0 ; money <= M ; money++)
    		if (reachable[C-1][money] == true)
    			break;

    	if (money == M+1)
    		cout << "no solution" << endl;
    	else
    		cout << M - money << endl;
    }
    	
    fclose (stdin);
    fclose (stdout);

    return 0;
}