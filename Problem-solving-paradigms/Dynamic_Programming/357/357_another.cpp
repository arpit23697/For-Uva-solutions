#include <bits/stdc++.h>
using namespace std;
long long int coins[5];
long long int ans[5][30010];

long long int ways (int id , int value)
{
	if (value == 0)
		return 1;
	if (value < 0)
		return 0;
	if (id > 4)
		return 0;

	if (ans[id][value] != -1)
		return ans[id][value];

	return ans[id][value] =  ways (id + 1 , value) + ways (id  , value - coins[id]);

}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

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
    	for (int i = 0 ; i < 5 ; i++)
    		for (int j = 0 ; j < 30010 ; j++)
    			ans[i][j] = -1;
	    long long int memo = ways (0 , n);

	    if (memo != 1)
	    printf ("There are %lld ways to produce %lld cents change.\n", memo , n);
		else
		printf ("There is only %lld way to produce %lld cents change.\n", memo , n);	
	}
    return 0;
}
