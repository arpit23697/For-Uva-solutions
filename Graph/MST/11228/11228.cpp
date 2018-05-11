#include <bits/stdc++.h>
#include <math.h>
using namespace std;

class unionFind
{
  public:
    int *rank;
    int *parent;
    int n;

    unionFind(int size)
    {
        n = size;
        rank = (int *)malloc(n * sizeof(int));
        parent = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (parent[u] == u)
            return u;

        int v = find(parent[u]);
        parent[u] = v;
        return v;
    }

    void Union(int u, int v)
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


    int test;
    cin >> test;
    int cases =0 ;
    while (test--)
    {
        cases++;
        int n , threshold;
        cin >> n >> threshold;

        vector <pair <int , int>> vertices;
        map <pair <int , int > , int > map1;
        for (int i= 0 ; i < n ; i++)
        {
            int x , y;
            cin >> x >> y;
            vertices.push_back (make_pair (x , y));
            map1.insert (make_pair (make_pair (x , y) , i));
        }
        vector <pair <double , pair <int, int>>> edges;
        for (int i= 0 ; i < n ; i++)
        {
            for (int j = i+1 ; j < n ; j++)
            {
                pair <int , int > p1 , p2;
                p1 = vertices[i];
                p2 = vertices[j];
                
                double dist = pow ((p1.first - p2.first), 2) + pow ((p1.second - p2.second) , 2);
                dist = sqrt (dist);
                //cout << p1.first << " " << p1.second << "   " << p2.first << " " << p2.second << "---" << dist << endl;
                edges.push_back (make_pair (dist , make_pair (map1[p1] , map1[p2])));
            }
        }
        /*
        for (map<pair<int, int>, int> :: iterator itr = map1.begin( ) ; itr != map1.end() ; ++itr)
        {
            pair <int , int > p = itr->first;
            int maped = itr -> second;
            cout << p.first << " " << p.second << " " << maped << endl;
        }*/
        
        sort(edges.begin(), edges.end());
        //for (int i = 0 ; i < edges.size() ; i++)
        //cout << edges[i].second.first << " " << edges[i].second.second << " --- " << edges[i].first << endl;
        //cout << endl;


        int states = 0;
        double roads = 0;
        double rails = 0;
        int count = 0;
        unionFind myUnion = unionFind ( edges.size());
        for (int i =0 ; i < edges.size() ; i++)
        {
            if (count == n-1)
                break;

            pair <double , pair <int , int >> p;
            p = edges[i];
            int x = p.second.first;
            int y = p.second.second;
            if (myUnion.find(x) != myUnion.find(y))
            {
                myUnion.Union (x , y);
                //cout << edges[i].second.first << " " << edges[i].second.second << " --- " << edges[i].first << endl;
                count++;

                if (p.first <= threshold)
                    roads += p.first;
                else
                {
                    rails+= p.first;
                    states++;
                }
            }
        }
        states++;
 //       cout << states << " " << rails << " " << roads << endl;
        int railInt = round(rails);
        int roadInd = round(roads);
        printf("Case #%d: %d %d %d\n",cases , states , roadInd ,railInt  );
    }
    return 0;
}