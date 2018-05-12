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

vector <pair <int , pair <int , int >>> edges;
int n , m;

int minimumSpanningTree (int notUse)
{
        unionFind myUnion = unionFind (n);
        int count = 0;
        int ans1 =0 ;
        int components = n;
        for (int i =0 ; i < m ; i++)
        {
            if (count == n-1)
            break;

            if (i == notUse)
            continue;

            pair <int , pair <int , int >> p = edges[i];
            int x = edges[i].second.first;
            int y = edges[i].second.second;
            if (myUnion.find(x) != myUnion.find(y))
            {
                count++;
                components--;
                myUnion.Union(x , y);
                ans1 += edges[i].first;
            }
        }
        if (components == 1)
        return ans1;
        else
        return 1000000;
}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    int test;
    cin >> test;
    
    while (test--)
    {
        
        cin >> n >> m;
        edges.clear();
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
        vector <int> vec;
        int ans1 =0 ;
        for (int i =0 ; i < m ; i++)
        {
            if (count == n-1)
            break;

            
            pair <int , pair <int , int >> p = edges[i];
            int x = edges[i].second.first;
            int y = edges[i].second.second;
            if (myUnion.find(x) != myUnion.find(y))
            {
                
                vec.push_back (i);
                count++;
                myUnion.Union(x , y);
                ans1 += edges[i].first;
            }
        }


       // cout << ans1 << endl;
       // for (int i= 0; i < vec.size() ; i++)
       // cout << vec[i] << " ";
       // cout << endl;
        int ans2 = 0;
        ans2 = minimumSpanningTree (vec[0]);
        for (int i= 1 ; i < vec.size() ; i++)
        {
            ans2 = min (ans2 , minimumSpanningTree(vec[i]));
        }
        cout << ans1 << " " << ans2 << endl;
        
     }
     return 0;
}