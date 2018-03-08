#include <bits/stdc++.h>
using namespace std;
long long int sum , n , coins[110];
long long int memo_change[110][20000];
long long int totalSum;
long long int memo[110][20000];



long long int solveChange (long long int id , long long int value)
{
	//cout << value << " " << id << endl;

	if (value >= sum )
		return memo_change[id][value] = (value - sum);

	if (id == n)
		return memo_change[id][value] = INT_MAX;

	if (memo_change[id][value] != -1)
		return memo_change[id][value];
	
	 return memo_change[id][value] = min ( (solveChange (id + 1 , value + coins[id])) , solveChange (id+1 , value));
	

}


long long int denomination (long long int id , long long int value)
{
	//cout << value << " "<<id <<endl;
	if (value > totalSum)
		return memo[id][value] = INT_MAX;

	if (id > n)
		return memo[id][value] = INT_MAX;

	if (value == totalSum)
		return memo[id][value] = 0;

	if (memo[id][value]!= -1)
		return memo[id][value];

	return memo[id][value] = min ( denomination (id + 1 , value) , 1 + denomination( id + 1 , value + coins[id])  );
}

int main ()
{	
	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);

	int test;
	cin >> test;
	while (test--)
	{
		cin >> sum;
		cin >> n;
		for (int i = 0 ; i < n ; i++)
			cin >> coins[i];

		memset (memo_change , -1 , sizeof memo_change);
		memset (memo , -1 , sizeof memo);
		long long int change = solveChange (0 ,0);
		

		totalSum = sum + change;


		long long int ans = denomination ( 0 ,0);

		cout << totalSum << " " << ans << endl;
		

	}

	return 0;
}	