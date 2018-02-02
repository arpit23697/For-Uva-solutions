#include <bits/stdc++.h>
using namespace std;
int graph[100][100];
long long int memo[15][10000];
int n;

long long int solve (int pos , long long int mask)
{
  //  cout << pos << " " << mask << endl;
    if (mask == pow (2 , n) - 1)
        return memo[pos][mask] = graph[pos][0];

    if (memo[pos][mask] != -1)
        return memo[pos][mask];

    long long int mini = INT_MAX;
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

    int test;
    cin >> test;
    int cases = 0;
    while (test--)
    {
        cases++;
        int temp1 , temp2;
        cin >> temp1 >> temp2 ;


        memset (graph , 0 , sizeof graph);
        memset (memo , -1 , sizeof memo);

        set <pair <int , int>> mySet;
        int x , y;
        cin >> x >> y;

        mySet.insert (make_pair (x , y));

        cin >> n;

        for (int i =1  ;i <= n ;i++)
        {
            int a , b;
            cin >> a >> b;
 
            mySet.insert (make_pair (a , b));
        }
        n = mySet.size();
        vector <pair <int , int>> vec;
        for (set <pair <int , int>> :: iterator itr = mySet.begin() ; itr != mySet.end() ; ++itr)
        {
            vec.push_back (*itr);
         //   cout << (*itr).first << " " << (*itr).second << endl;
        }

        for (int i = 0  ; i < n ; i++ )
        {
            for (int j = i ; j < n ; j++)
            {
                int temp = abs (vec[j].first - vec[i].first) + abs (vec[j].second - vec[i].second);
                graph[i][j] = temp;
                graph[j][i] = temp;
               // cout << graph[i][j] << " ";
            }
         //   cout << endl;
        }
        long long int ans = solve (0 , 1);
        printf ("The shortest path has length %lld\n",ans);
    }

    return 0;

}