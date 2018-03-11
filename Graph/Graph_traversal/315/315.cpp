#include <bits/stdc++.h>
using namespace std;

vector <vector  <int>> graph;
int n;
vector <int> dfs_num;
vector <int> dfs_low;
int UNVISITED = -1;
vector <int> parent;
vector <bool> articulation;
int dfs_counter ;
int dfs_root;
int root_children;

void Articulation_and_bridges (int u)
{
    
    dfs_num[u] = dfs_low[u] = dfs_counter;              //dfs_low[u] <= dfs_num[u]
    dfs_counter++;

    for (int i= 0 ; i < graph[u].size() ; i++)
    {
        int v = graph[u][i];
        if (dfs_num[v] == UNVISITED)
        {
            parent[v] = u;
            if (u == dfs_root) 
                root_children++;

            Articulation_and_bridges(v);

            if (dfs_low[v] >= dfs_num[u]) 
            articulation[u] = true;
            dfs_low[u] = min (dfs_low[u] , dfs_low[v]);   
        }
        else if ( v != parent[u])                //this is one the back edge
        dfs_low[u] = min (dfs_low[u] , dfs_num[v]);
    }

}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    while (1)
    {
        graph.clear ();
        string line;
        cin >> n;
        //cout << n << endl;
        if (n == 0)
        break;
        getline (cin , line);
        graph.assign (n , vector <int> ());

        while (1)
        {
            getline (cin , line);
            //cout << line << endl;
            istringstream iss(line);
            int source;

            
            iss >> source;
            if (source == 0)
                break;

            int destination;
            while (iss >> destination)
            {
          //      cout << source << " " << destination << endl;
                graph[source-1].push_back (destination-1);
                graph[destination-1].push_back(source-1);
            }
        }
/*
    for (int i =0 ; i < n ; i++)
    {
        cout << i;
        for (int j = 0 ; j < graph[i].size() ; j++)
        {
            int v = graph[i][j];
            cout << " " << v ;
        }
        cout << endl;
    }
        cout << "hii " << endl << endl << endl;
*/
    dfs_num.clear();
    dfs_low.clear();
    articulation.clear();
    parent.clear();

    dfs_num.assign (n , UNVISITED);
    dfs_low.assign (n , -1);
    articulation.assign (n , false);
    parent.assign(n , -1);
    

        dfs_counter = 0;

        dfs_root = 0;
        root_children = 0;
        Articulation_and_bridges (0);
       //    cout << root_children << "children \n";
           if (root_children > 1)
           articulation[0] = true;
           else 
           articulation[0] = false;

    //cout << "---" << dfs_counter << "---" << endl;    

    //for (int i= 0  ; i < n ; i++)
       // cout << i  << " "<<dfs_num[i] << " " << dfs_low[i] <<  "  " << parent[i] << endl;
    int ans = 0;
    for (int i =0  ; i < n ; i++)
    {    
        if (articulation[i] == true)
           // cout << "---" << i << "---" << endl;
        ans++;
       
        //cout << articulation[i] << endl;
    
    }
    cout << ans<< endl;

    }
    return 0;
} 