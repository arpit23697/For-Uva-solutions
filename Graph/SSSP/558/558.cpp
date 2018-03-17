#include <bits/stdc++.h>
using namespace std;

vector <vector <pair <int , int >>> graph;
int dist[1005];
int n;

bool bellman (int source)
{
    memset (dist , 1000000 , sizeof dist);
    dist[source] = 0;
    
    for (int ro =0 ;  ro < n-1 ; ro++ )
    {
        bool flag = false;
        for (int i =0  ; i < n ; i++)
        {
            int u = i;
            for (int j = 0 ; j < graph[u].size() ; j++)
            {
                pair <int , int > p = graph[u][j];
                int v = p.first;
                int weight = p.second;
                if (dist[v] > dist[u] + weight )
                {
                    dist[v] = dist[u] + weight;                }
                    flag = true;
                }
        }
        if (flag == false)
        return false;
    }

    for (int i= 0  ; i < n ; i++)
    {
        int u = i;
        for (int j =0 ; j < graph[i].size() ; j++)
        {
            pair<int, int> p = graph[u][j];
            int v = p.first;
            int weight = p.second;
            if (dist[v] > dist[u] + weight)
            return true;
        }
    }
    return false;
}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);

    int test;
    cin >> test;

    while(test--)
    {
        int  m;
        cin >> n >> m;

        graph.assign (n , vector <pair <int , int >>() );
        for (int i = 0 ; i < m ; i++)
        {
            int x , y , weight;
            cin >> x >> y >> weight;
            graph[x].push_back (make_pair (y , weight));
        }

        if ( bellman (0))
        cout << "possible" << endl;
        else
        cout << "not possible" << endl;
    }
    return 0;
}