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
int M , C , price[25][25];
int memo[210][25]; 			//for storing the memo values

int shop (int money , int g)
{
	if (money < 0) return -10000000;
	if (g == C) return M - money;

	if (memo[money][g] != -1) return memo[money][g];
	int ans = -1;
	for (int model = 1 ; model <= price[g][0] ; model++)
		ans = max (ans , shop (money - price[g][model] , g+1));

	memo[money][g] = ans;
	return ans;
}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);

    int test;
    cin >> test;
    while (test--)
    {
    	cin >> M >> C;
    	for (int i = 0 ; i < C ; i++)
    	{
    		cin >> price[i][0];
    		for (int j =1 ; j <= price[i][0] ; j++)
    			cin >> price[i][j];

    	}

    	memset (memo , -1 , sizeof memo);

    	int score = shop (M , 0);
    	if (score < 0)
    		cout << "no solution" << endl;
    	else
    		cout << score << endl;
    }


    fclose (stdin);
    fclose (stdout);

    return 0;
}