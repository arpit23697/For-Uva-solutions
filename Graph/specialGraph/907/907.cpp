#include <bits/stdc++.h>
using namespace std;

int n , k;
int distanceToGo[610];
int memo[605][305];

int solve (int campsite , int nightsLeft)
{
    if (campsite == n)
    return 0;

    if (nightsLeft == 0)
    {
        int ans= 0;
        for (int i = campsite ; i < n ; i++)
        ans+= distanceToGo[i];

        return ans;
    }
    if (memo[campsite][nightsLeft] != -1)
    return memo[campsite][nightsLeft];

    int best = 100000000;
    int distance = distanceToGo[campsite];

    for (int next = campsite + 1 ; next <= n && best > distance ; distance += distanceToGo[next] , ++next)
    {
        best = min (best , max (distance , solve (next , nightsLeft-1)));
    }
    return memo[campsite][nightsLeft] = best;
}


int main ()
{
    freopen ("in.txt", "r" , stdin);
    freopen ("out.txt",  "w" , stdout);
    while (scanf("%d %d", &n , &k) == 2)
    {
        ++n;
        for (int i= 0 ; i < n ; i++)
        cin >> distanceToGo[i];

        for (int i=0 ; i < n ; i++)
        for (int j = 0 ; j <= k ; j++)
        memo[i][j] = -1;

        cout << solve(0 , k) << endl;
    }   
    return 0; 
}