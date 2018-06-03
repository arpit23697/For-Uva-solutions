#include <bits/stdc++.h>
using namespace std;
vector <vector <pair <int ,int >>> graph;
int n , start , times;

vector <int> dist;
int inf = 10000000;

void dijkstra (int start)
{
    dist.assign (n , inf);
    dist[start] = 0;

    priority_queue <pair <int ,int > , vector <pair <int ,int >> , greater <pair <int ,int >>> pq;
    pq.push(make_pair (0 , start));

    while (!pq.empty())
    {
        pair <int ,int > p = pq.top();
        pq.pop();
        int u = p.second;
        int d = p.first;

        if (d > dist[u])
        continue;

        for (int i= 0 ; i < graph[u].size() ; i++)
        {
            pair <int , int> v = graph[u][i];
            if (dist[v.first] > dist[u] + v.second)
            {
                dist[v.first] = dist[u] + v.second;
                pq.push(make_pair (dist[v.first] , v.first));
            }
        }
    } 
}


int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n >> start >> times;
        start--;
        int edges;
        cin >> edges;
        graph.assign (n , vector <pair <int , int>> ());

        for (int i=0 ; i < edges ; i++)
        {
            int x , y , we;
            cin >> x >> y >> we;
            x--;
            y--;
            graph[y].push_back(make_pair (x , we));

        }

        dijkstra (start);
       // for (int i= 0 ; i < n ; i++)
       // cout << dist[i] << " ";
       // cout << endl;

        int ans = 0;
        for (int i= 0 ; i < n ; i++)
        if (dist[i] <= times)
        ans++;
        cout << ans<< endl;
        if (test > 0)
        cout << endl;
    }

    return 0;
}