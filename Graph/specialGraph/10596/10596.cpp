#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> graph;
vector <bool> visited;

void dfs (int start)
{
    visited[start] = true;
    for (int i= 0 ; i < graph[start].size() ; i++)
    {
        int v = graph[start][i];
        if (visited[v] == false)
        dfs (v);
    }
}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);

    int n , m;
    while (scanf("%d %d",&n , &m) == 2)
    {
    // cout << n << " " << m << endl;

        vector <int> degrees(n);
        graph.assign (n , vector <int> ());
        //set < pair <int , int> > mySet;
       // pair < set <pair <int , int >> :: iterator , bool > ret;

        for (int i= 0 ; i < m ; i++)
        {
            int x , y;
            cin >> x >> y;
            
      //      ret = mySet.insert (make_pair (x , y));
      //     cout << x << " " << y << endl;
            
                degrees[x]++;
                degrees[y]++;
                graph[x].push_back(y);
                graph[y].push_back(x);
            
        }
        bool possible = true;
        visited.assign(n, false);
        

      //  for (int i= 0 ; i < n ; i++)
      //  cout << degrees[i] << " ";
      //  cout << endl;

        int total = 0;
        int start = -1;
        for (int i=0  ; i < n ; i++)
        {
            if (degrees[i]%2 != 0)
            total++;
            if (degrees[i] != 0 && start == -1)
            start = i;
        }
        
        if (total > 0)
        possible = false;

        if (start == -1)
            possible = false;
        else
            dfs(start);

        for (int i =0 ; i< n ; i++)
        {
            if (graph[i].size() == 0)
            continue;

            if (visited[i] == false)
            {
                possible = false;
                break;
            }
        }
        if (possible)
        cout << "Possible" << endl;
        else
        cout << "Not Possible" << endl;
    }
    return 0;
}