#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	long long int coins[5];
    coins[0] = 1;
	coins[1] = 5;
	coins[2] = 10;
	coins[3] = 25;
	coins[4] = 50;

	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);

    long long int n;
   
    while (scanf ("%lld" , &n) == 1)
    {
	    long long int memo[5][n+1];
	    for (long long int i = 0 ; i < 5 ; i++)
	    {
	        memo[i][0] = 1;
	    }
	    
	    
	    for (long long int j = 0 ; j <= n ; j++ )
	    {
	        if (j % coins[0] == 0)
	            memo[0][j] = 1;
	        else
	            memo[0][j] = 0;
	    }


	    for (long long int i = 1 ; i < 5 ; i++ )
	        for (long long int j = 1 ; j <= n ; j++)
	        {
	            if (j < coins[i])
	                memo[i][j] = memo[i-1][j];
	            else
	            {
	                memo[i][j] = memo[i-1][j] + memo[i][j-coins[i]];
	            }

	        }
	    if (memo[4][n] != 1)
	    printf ("There are %lld ways to produce %lld cents change.\n", memo[4][n] , n);
		else
		printf ("There is only %lld way to produce %lld cents change.\n", memo[4][n] , n);	
	}
    return 0;
}
