#include <bits/stdc++.h>
using namespace std;

long long int memo[110][110];

long long int ways (int n , int k)
{
	if (k == 1)
		return memo[n][k] = 1;

	if (memo[n][k] != -1)
		return memo[n][k] % 1000000;

	long long int ans = 0;
	for (int i = 0 ; i <= n ; i++)
		ans += ways (n - i , k-1);

	return memo[n][k] = ans % 1000000;
}


int main ()
{
	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);

	while (1)
	{
		int n, k;
		cin >> n >> k;

		if (n == 0 && k == 0)
			break;


		memset (memo , -1 , sizeof memo);
		long long int ans = ways (n , k);
		cout << ans << endl;
	}

	return 0;
}
