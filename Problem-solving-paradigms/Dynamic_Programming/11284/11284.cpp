#include <bits/stdc++.h>
using namespace std;
double graph[100][100];
long long int memo[10][10000];
int n;

double solve (int pos , long long int mask)
{

    if (mask == pow (2 , n) - 1)
        return memo[pos][mask] = graph[pos][0];

    if (memo[pos][mask] != -1)
        return memo[pos][mask];

    double mini = INT_MAX;
    for (int next = 0 ; next < n; next++)
    {
        if (next != pos && (mask & (1 << next)) == 0 )
            mini = min (mini , graph[pos][next] + solve (next , mask | (1 << next)));
    }
    
    return memo[pos][mask] = mini;
}

int main ()
{
    freopen ("in.txt" , "r" , stdin );
    freopen ("out.txt" , "w" , stdout);

    cin >> n;


    for (int i =0 ; i < n ; i++)
        for (int j = 0 ; j < n; j++)
            cin >> graph[i][j];

    memset (memo , -1 , sizeof memo);
    double ans = solve (0 , 1);
    cout << ans << endl;

    return 0;

}