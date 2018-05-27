#include <bits/stdc++.h>
using namespace std;

vector <vector <pair <int , int>>> graph;
int total;
vector <bool> visited;
vector <int> topological;
int inf = 1000000;

void dfs (int start)
{
    visited[start] = true;                    
    for (int i=0 ; i < graph[start].size() ; i++)
    {
        pair <int , int >p = graph[start][i];
        int v = p.first;
        if (visited[v] == false)
        dfs (v);
    }           
    topological.push_back(start);
}


int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);

    char str[100];
    while(scanf("%s", str) == 1)
    {
        //cout << str << endl;

        topological.clear();
        visited.clear();
        graph.clear();

        int roofs , holes;
        cin >> roofs >> holes;

        total = roofs*holes + 2;
        graph.assign (total , vector <pair<int ,int>>() );

        for (int i= 1 ; i <= holes ; i++)
        graph[0].push_back (make_pair (i , 0));


        //i is the roof
        //j is the hole number
        for (int i= 0 ; i < roofs-1 ; i++ )
        {
            for (int j = 0 ; j < holes ; j++)
            {
                for (int k=0 ; k < holes ; k++)
                {
                    int x;
                    cin >> x;
                   // cout << x << " ";
                    graph[i*holes+j+1].push_back(make_pair( ((i+1)*holes+k+1) , x ));
                }
        
            }
        }

        for (int i = 1 ; i<=holes ; i++)
        graph[ (roofs-1)*holes+i].push_back(make_pair (total -1 , 0));

        visited.assign (total , false);
        dfs(0);

        vector <int> dist;
        dist.assign (total , inf);
        dist[0] = 0;

        for (int i = topological.size()-1 ; i>= 0 ; i--)
        {
            int u = topological[i];
            for (int j=0 ; j < graph[u].size() ; j++ )
            {
                pair <int , int > p = graph[u][j];
                int v = p.first;
                int we = p.second;
                if (dist[v] > dist[u] + we)
                    dist[v] = dist[u]+we;
                
            }
        }
        cout << str << endl;
        cout << dist[total-1] + 2 * (roofs-1) << endl;

    }
    return 0;
}