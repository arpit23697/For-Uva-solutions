#include <bits/stdc++.h>
using namespace std;
long long int m , sum;
long long int A[310] , B[310];
long long int memo [45][310][310];

long long int solve (int id , int a , int b)
{
	if (a*a + b*b == sum * sum)
		return 0;
	
	if ((a*a + b*b) > sum * sum || id >= m)
		return INT_MAX;

	if (memo[id][a][b] != -1)
		return memo[id][a][b];

	return memo[id][a][b] = min (solve (id+1 , a , b) ,1 + solve (id , a + A[id] , b + B[id]));
}

int main ()
{
	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);

	long long int n;
	cin >> n;

	while (n--)
	{
		cin >> m >> sum;
		for (int i = 0 ; i < m ; i++)
			cin >> A[i] >> B[i];

		for (int i = 0; i < 45 ; i++)
			for (int j = 0 ; j < 310 ; j++)
				for (int k = 0 ; k < 310 ; k++)
					memo[i][j][k] = -1;

		long long int ans = solve (0 , 0 , 0); 

		if (ans == INT_MAX || ans == -1)
			cout << "not possible" << endl;
		else
			cout << ans << endl;

	}
	return 0;
}