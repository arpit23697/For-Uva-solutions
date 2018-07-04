#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    while (1)
    {
        int n;
        double p;
        cin >> n;
        if (n == 0)
        break;
        cin >> p;
        double dp[n+5][n+5];


        for (int i =0 ; i <= n ; i++)
        for (int j = i ; j <= n ; j++)
        dp[i][j] = 1.0;
        
        
        for (int i = 1 ; i <= n ; i++)
        dp[i][i-1] = 1 - pow (p , i);

        for (int i = 2 ; i <= n ; i++)
        for (int j = 0 ; j < i-1 ; j++)
            dp[i][j] = dp[i-1][j] - dp[i-j-2][j] * (1 - p) * pow (p , j+1);
        
        double ans = 0;
        for (int i = 1; i <= n ; i++)
        ans += i * (dp[n][i] - dp[n][i-1]);

        printf ("%.10lf\n" , ans);
    }
    return 0;
}