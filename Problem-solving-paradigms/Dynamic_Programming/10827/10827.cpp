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

	int cases;
	scanf ("%d",&cases);
	while (cases--)
	{
		int n;
		scanf ("%d",&n);
		long long int a[n][n];
		long long int sum[n][n];
		long long int rowSum[n];
		long long int colSum[n];

		memset (rowSum , 0 , sizeof rowSum);
		memset (colSum , 0 , sizeof colSum);
		long long int total = 0;

		for (int i = 0; i < n ;i++)
			for (int j = 0 ; j < n ; j++)
			{
				scanf ("%lld",&a[i][j]);
				sum[i][j] = a[i][j];
				if (i > 0)sum[i][j] += sum[i-1][j];
				if (j > 0)sum[i][j] += sum[i][j-1];
				if (i > 0 && j > 0 )sum[i][j] -= sum[i-1][j-1];
				total += a[i][j];
				rowSum[i] += a[i][j];
				colSum[j] += a[i][j];
			}


		long long int ans = a[0][0];
		for (int i = 0 ; i < n ; i++)
			for (int j = 0 ; j < n ; j++)
				for (int k = i; k < n ; k++ )
					for (int l = j ; l < n ; l++)
					{	
						//cout << i << "  " << j << "     " << k << "  " << l << endl;
						long long int temp ;
						temp = sum[k][l];
						if (i > 0)temp -= sum[i-1][l];
						if (j  > 0)temp -= sum[k][j-1];
						if (i > 0 && j > 0)temp += sum[i-1][j-1];
					
						ans = max (temp , ans);
						//cout << temp << " " ;

						long long int row = 0;
						if (l-j+1 != n)
						{	
							
							for (int x = i ; x <= k ; x++)
								row += rowSum[x];


							long long int t2 = row - temp;
							ans = max (t2 , ans);
						//	cout << t2 << " ";
						}

						long long int col = 0;
						if (k - i + 1 != n)
						{
							for (int x = j ; x <= l ; x++ )
								col += colSum[x];

							long long int t3 = col - temp;
							ans = max (t3 , ans);
						//	cout << t3 << " ";
						}

						if (l-j+1 != n && k - i + 1 != n )
						{
							long long int t4 = total - row - col + temp;
							ans = max (t4 , ans);
						//	cout << t4 << " " << endl;
						}
						//cout << endl;


					}

		cout << ans << endl;

	}

	fclose (stdin);
	fclose (stdout);
	return 0;
}