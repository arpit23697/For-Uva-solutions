
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

    
        int v , e;
        cin >> v >> e;

        if (v == 0 && e == 0)
            break;
        vector <pair <int , pair <int , int>>> edges;
        
        long long int total = 0;
        for (int i = 0 ; i < e ; i++)
        {
            int a , b , wt;
            cin >> a >> b >> wt;
            edges.push_back ( make_pair (wt , make_pair (a , b)) );
            total += wt;
        }

        sort (edges.begin() , edges.end());
        int counter = 0;
        unionFind mySet = unionFind (v);
        int i = 0;
        long long int ans = 0;
        while (counter != v-1)
        {
            pair <int , pair <int , int>> p = edges[i];
            i++;
            int weight = p.first;
            int a = p.second.first;
            int b = p.second.second;

            if (mySet.find(a) != mySet.find(b))
            {
                mySet.Union ( a , b);
                counter++;
                ans += weight;
            }
            //cout << "hi " << endl;
         }
        
        cout << total - ans << endl;
    }
    return 0;
}