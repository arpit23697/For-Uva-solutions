#include <bits/stdc++.h>
using namespace std;

int n;
vector <vector <pair <int ,int >>> graph;
vector <vector <pair <int ,int >>> reverse_graph;
int start , destination , threshold;

int inf = 10000000;
vector <int> dist;


void dijekstra (int start)
{
    dist.assign (n , inf);
    dist[start] = 0;

    priority_queue < pair <int , int> , vector <pair <int ,int>> , greater <pair <int , int >>> pq;
    pq.push(make_pair (0, start));

    while (!pq.empty())
    {
        pair <int ,int > p = pq.top();
        pq.pop();
        int u = p.second;
        int d = p.first;

        if (d > dist[u])
        continue;

        for (int i= 0; i < graph[u].size() ; i++)
        {
            pair <int , int > v = graph[u][i];
            if (dist[v.first] > dist[u] + v.second)
            {
                dist[v.first] = dist[u] + v.second;
                pq.push (make_pair (dist[v.first] , v.first));
            }

        }
    }

}

vector <int> dist_reverse;
void dijekstra2(int destination)
{
    dist_reverse.assign(n, inf);
    dist_reverse[destination] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, destination));

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int u = p.second;
        int d = p.first;

        if (d > dist_reverse[u]) 
            continue;

        for (int i = 0; i < reverse_graph[u].size(); i++)
        {
            pair<int, int> v = reverse_graph[u][i];
            if (dist_reverse[v.first] > dist_reverse[u] + v.second)
            {
                dist_reverse[v.first] = dist_reverse[u] + v.second;
                pq.push(make_pair(dist_reverse[v.first], v.first));
            }
        }
    }
}

int main ()
{
    freopen ("in.txt" , "r" ,  stdin);
    freopen ("out.txt" , "w" , stdout);

    int test;
    cin >> test;
    while (test--)
    {
        int edges;
        cin >> n >> edges >> start >> destination >> threshold;
      //  cout << n << " " << edges << " " << start << " " << destination << " " << threshold << endl;
        start--;
        destination--;
        
        graph.assign (n , vector <pair <int ,int>>());
        reverse_graph.assign(n , vector <pair <int , int>>());
        for (int i= 0 ; i < edges ; i++)
        {
            int x ,y,we;
            cin >> x >>y >>we;
            x--;
            y--;
            graph[x].push_back(make_pair (y , we));
            reverse_graph[y].push_back(make_pair (x , we)); 
         //   graph[y].push_back(make_pair (x , we));
        }

        dijekstra(start);
        dijekstra2(destination);

      //  for (int i= 0 ; i < n ; i++)
      //  cout << dist[i] << " " << dist_reverse[i] << endl;
      //  cout << endl;
        int ans = -1;
        for (int i= 0 ; i < n ; i++)
        {
            int u = i;
            for (int j =0 ; j < graph[u].size() ; j++)
            {
                pair <int ,int> v = graph[u][j];
                if (dist[u] + dist_reverse[v.first] + v.second <= threshold)
                ans = max (ans , v.second);
        //        cout << u+1 << " " << v.first << " "<< ans << endl;
            }
        }
        cout << ans << endl;
    }

    return 0;
}