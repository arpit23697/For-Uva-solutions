#include <bits/stdc++.h>
using namespace std;
long long int a[1000] , d , m , n , memo[1000][100][100];



long long int solve (int id , int sum , int k)
{
	if (k == m && sum == 0)
		return 1;
	if (k == m && sum != 0)
		return 0;
	if (id == n && k < m )
		return 0;

	if (memo[id][sum][k] != -1)
		return memo[id][sum][k];

	return memo[id][sum][k] = solve (id + 1 ,(a[id] + sum)%d , k + 1) + solve (id + 1 , sum , k);
}

int main ()
{
	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);

	int t = 0;
	while (1)
	{
		t++;
		long long int Q;
		cin >> n >> Q ;

		if (n == 0 && Q == 0)
			break;

		for (int i =0 ; i < n ; i++)
			cin >> a[i];

		cout << "SET " << t << ":" << endl;
		for (int i =0  ; i < Q ; i++)
		{
			memset (memo , -1 , sizeof memo);
			cout << "QUERY " << i+1 << ": ";
			cin >> d >> m;

			cout << solve(0 , 0 , 0) << endl;
		}
	}

	fclose (stdin);
	fclose (stdout);
}