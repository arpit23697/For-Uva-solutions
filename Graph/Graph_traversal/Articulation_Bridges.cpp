#include <bits/stdc++.h>
using namespace std;

vector <vector  <int>> graph;
int n;
vector <int dfs_num;
vector <int> dfs_low;
int UNVISITED = 0;
vector <int> parent;
vector <bool> articulation;
int dfs_counter;
int dfs_root;
int root_children;

void Articulation_and_bridges (int u)
{
    dfs_num[u] = dfs_low[u] = dfs_counter;              //dfs_low[u] <= dfs_num[u]
    dfs_counter++;
    for (int i= 0 ; i < graph[u].size() ; i++)
    {
        int v = graph[u][v];
        if (dfs_num[u] == UNVISITED)
        {
            parent[v] = u;
            if (u == dfs_root) 
                root_children++;

            Articulation_and_bridges(v);

            if (dfs_low[v] >= dfs_num[u]) 
            articulation[u] = true;
            if (dfs_low[v] > dfs_num[u])
            cout << u << " " << v << "  is a bridge edge " << endl;
            dfs_low[u] = min (dfs_low[u] , dfs_low[v]);   
        }
        else if (v != parent[u])                //this is one the back edge
        dfs_low[u] = min (dfs_low[u] , dfs_num[v]);
    }

}

int main ()
{
    cin >> n;
    int edges;
    cin >> edges;
    graph.assign (n , vector <int> ());
    for (int i = 0 ; i < edges ; i++)
    {
        int a , b;
        cin >> a >> b;
        graph[a].push_back (b);
    }
    dfs_num.assign (n , 0);
    dfs_low.assign (n , 0);
    articulation.assign (n , false);
    parent.assign(n , 0);
    dfs_counter = 0;

    for (int i = 0 ; i < n ; i++)
        if (dfs_num[i] == UNVISITED)
        {
            dfs_root = i;
            root_children = 0;
            Articulation_and_bridges (i);
            if (root_children > 1)
            articulation[i] = true;
        }

    for (int i =0  ; i < n ; i++)
        if (articulation[i] == true)
        cout << i << " ";

    cout << endl;

    return 0;
    
} 