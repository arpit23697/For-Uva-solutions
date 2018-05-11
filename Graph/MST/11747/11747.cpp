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

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    while (1)
    {
        int n , m;
        cin >> n >> m;
        if (n == 0 && m == 0)
        break;

        vector <pair <int , pair <int , int >>> edges;
        for (int i =0  ; i < m ; i++)
        {
            int u , v , w;
            cin >> u >> v >> w;
            edges.push_back (make_pair (w , make_pair(u , v)));
        }
        sort (edges.begin() , edges.end());
        unionFind myUnion = unionFind (n);
        bool taken[m];
        memset (taken , false , sizeof taken);
        int count = 0;
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
                myUnion.Union(x , y);
                taken[i] = true;
            }
        }
        vector <int > ans;
        for (int i= 0 ; i < m ; i++)
        {
            if (taken[i] == false)
            ans.push_back(edges[i].first);
        }
        if (ans.size() == 0)
        cout << "forest" << endl;
        else
        {
            cout << ans[0];
            for (int i = 1 ; i < ans.size() ; i++)
            cout << " " << ans[i];
            cout << endl;
        }
     }
     return 0;
}