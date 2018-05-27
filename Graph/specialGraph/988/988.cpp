#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> graph;
int n;
vector <bool> death;
vector <int> topological;
vector <bool> visited;

vector <int> ways;


void dfs (int start)
{
   visited[start] = true;
   for (int i= 0 ; i < graph[start].size() ; i++)
   {
       int v = graph[start][i];
       if (visited[v] == false)
       dfs(v);
   } 
    topological.push_back(start);
}


int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt", "w" , stdout);
    cin >> n;
    while(1)
    {
        topological.clear();
        graph.assign (n , vector <int>() );
        death.assign (n , false);
        for (int i= 0 ; i < n ; i++)
        {
            int temp;
            cin >> temp;

            if (temp == 0)
            death[i] = true; 

            for (int j =0 ; j < temp ; j++)
            {
                int x;
                cin >> x;
                graph[i].push_back(x);
            }
        }
        visited.assign (n , false);
        dfs (0);

        ways.assign (n , 0);
        ways[0] = 1;

        for (int i = topological.size() - 1; i >= 0 ; i--)
        {
            int u = topological[i];
            for (int j= 0 ; j < graph[u].size() ; j++)
            {
                int v= graph[u][j];
                ways[v] += ways[u];
            }
        }

        long long int ans = 0;
        for (int i= 0 ; i < n ; i++)
        {
            if (death[i]==true)
            ans+=ways[i];
        }
        cout << ans << endl;

        if (cin >> n)
        cout << endl;
        else 
        break;
    }
}