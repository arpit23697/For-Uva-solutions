#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    int test;
    cin >> test;
    int cases = 0 ;
    while (test--)
    {
        cases++;
        int n;
        cin >> n;
        int R;
        cin >> R;

        int graph[n][n];
        for (int i= 0 ; i < n ; i++)
        for (int j =0 ; j < n ; j++)
        {
            graph[i][j] = 10000;
            if (i == j)
            graph[i][j] = 0;
        }
        for (int i = 0 ; i < R ; i++)
        {
            int u , v;
            cin >> u >> v;
            graph[u][v] = 1;
            graph[v][u] = 1;

        } 
        int s , d;
        cin >> s >> d;
        for (int k = 0 ; k < n ; k++)
            for (int i = 0 ; i < n ; i++)
                for (int j = 0 ; j < n; j++)
                graph[i][j] = min (graph[i][j] , graph[i][k] + graph[k][j]);
        
        int ans = -1;
        for (int  i = 0 ; i < n ; i++)
        ans = max (ans , graph[s][i] + graph[d][i]);

        printf ("Case %d: %d\n",cases , ans);
    }
    return 0;
}