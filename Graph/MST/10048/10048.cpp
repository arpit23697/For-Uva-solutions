#include <bits/stdc++.h>
using namespace std;
class unionFind
{
    public:
        int *rank;
        int *parent;
        int n;

    unionFind (int size)
    {
        n = size;
        rank = (int *)malloc (n * sizeof(int));
        parent = (int *)malloc (n * sizeof(int));

        for (int i =0 ; i < n ; i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int find (int u)
    {
        if (parent[u] == u)
            return u;

        int v = find(parent[u]);
        parent[u] = v;
        return v;
    }

    void Union (int u , int v)
    {
        int x = find(u);
        int y = find(v);

        if (x != y)
        {
            if (rank[x] == rank[y])
            {
                parent[y] = x;
                rank[x]++;
            }
            else if (rank[x] > rank[y])
                parent[y] = x;
            else
                parent[x] = y;
        }
    }
};

vector <bool> visited;
vector <pair <int , int>> pre;
vector <pair < pair <int , int > , int > > graph;
vector <vector <pair< int , int > >> vec;
int n;

void DFS (int start)
{
    visited[start] = true;
    for (int i = 0 ; i < vec[start].size() ; i++)
    {
        pair <int , int >p = vec[start][i];
        int u = p.first;
        int we = p.second;
        if (!visited[u])
        {
            pre[u] = make_pair (start , we);
            DFS (u);
        }
    }
}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    int cases = 0;
    int m, query;
    cin >> n >> m >> query;
    while (1)
    {
        cases++;
        
        
        
        vector <pair <int , pair <int , int >>> edges;
        for (int i =0  ; i < m ; i++)
        {
            int u , v , w;
            cin >> u >> v >> w;
            u--;
            v--;

            edges.push_back (make_pair (w , make_pair(u , v)));
        }
        sort (edges.begin() , edges.end());
        unionFind myUnion = unionFind (n);
       
        int count = 0;
        
        graph.clear();
        for (int i =0 ; i < m ; i++)
        {

            if (count == n-1)
            break;

            pair <int , pair <int , int >> p = edges[i];
            int x = edges[i].second.first;
            int y = edges[i].second.second;
            if (myUnion.find(x) != myUnion.find(y))
            {
                count++;
                graph.push_back ( make_pair (make_pair (x , y), edges[i].first ));
                myUnion.Union(x , y);
            }
        }

       // for (int i= 0 ; i < graph.size() ; i++)
       // {
       //     cout << graph[i].first.first << " " <<graph[i].first.second << " -- " << graph[i].second << endl;
       // }

        vec.assign (n , vector <pair <int ,int >>());
        for (int i= 0 ; i < graph.size() ; i++)
        {
            int x = graph[i].first.first;
            int y = graph[i].first.second;
            int we = graph[i].second;
            vec[x].push_back (make_pair(y , we) );
            vec[y].push_back (make_pair (x , we));
        }
/*
        for (int i=0 ; i < n ; i++)
        {
            cout << i << " ";
            for (int j =0 ; j < vec[i].size() ; j++)
            {
                cout << "(" << vec[i][j].first << "," << vec[i][j].second <<") ";
            }
            cout << endl;
        }*/

        printf("Case #%d\n",cases); 
        for (int i = 0; i < query; i++)
        {
            visited.assign ( n , false);
            pre.assign (n , make_pair (-1 , 0));
            int x ,y;
            cin >> x >> y;
            x--;
            y--;

            
            DFS (x);

            //for (int i= 0 ; i < n ; i++)
            //cout << pre[i].first << " " << pre[i].second << endl;
            //cout << endl;
            int ans;
            if (visited[y] == false)
            cout << "no path" << endl;
            else{
                ans = -10000000;
                int current = y;
                
                while (current != x)
                {
                    //cout << current << endl;
                    ans = max (ans , pre[current].second);
                    current = pre[current].first;
                    
                }
                cout << ans << endl;    
            }
            

        }
        cin >> n >> m >> query;
        if (n == 0 && m == 0 && query ==0 )
            break;
        else
        cout << endl;
     }
     return 0;
}