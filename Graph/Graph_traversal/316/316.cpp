#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
int n;
vector<int> dfs_num;
vector<int> dfs_low;
int UNVISITED = -1;
vector<int> parent;
int dfs_counter;
int dfs_root;
vector <pair <int , int>>  criticalPoints;

void Articulation_and_bridges(int u)
{

    dfs_num[u] = dfs_low[u] = dfs_counter; //dfs_low[u] <= dfs_num[u]
    dfs_counter++;

    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        if (dfs_num[v] == UNVISITED)
        {
            parent[v] = u;
      
            Articulation_and_bridges(v);

            if (dfs_low[v] > dfs_num[u])
                criticalPoints.push_back (make_pair ( min (u,v) , max(u ,v ) ));
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != parent[u]) //this is one the back edge
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while (scanf("%d", &n)  == 1)
    {
        graph.clear();
        char temp;        
        graph.assign(n, vector<int>());
        for(int y = 0 ; y < n ; y++)
        {
            int source;
            cin >> source;

            int negihbours;
            cin >> temp;
            cin >> negihbours;
            cin >> temp;

            for (int i =0  ; i < negihbours ; i++)
            {
                int destination;
                cin >> destination;
                graph[source].push_back(destination);
                graph[destination].push_back (source);

            }
        }

        dfs_num.clear();
        dfs_low.clear();
        parent.clear();
        criticalPoints.clear();

        dfs_num.assign(n, UNVISITED);
        dfs_low.assign(n, -1);
        parent.assign(n, -1);

        dfs_counter = 0;

        for (int i =0 ; i < n ; i++)
        if (dfs_num[i] == UNVISITED)
        Articulation_and_bridges(i);

        int size ;
    
        size = criticalPoints.size();
        printf("%d critical links\n", size);
        sort (criticalPoints.begin() , criticalPoints.end());
        for (int i = 0 ; i < size ; i++)
        cout << criticalPoints[i].first << " - " << criticalPoints[i].second << endl;

        cout << endl;
    }
    return 0;
}