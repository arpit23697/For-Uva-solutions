#include <bits/stdc++.h>
using namespace std;
int v , e;
vector <vector <pair <int , int>>> graph;
long long int dist[20005];

void diskstra (int start)
{
    priority_queue< pair <int , int > , vector< pair <int , int >>, greater<pair <int , int>> > q;
    q.push (make_pair ( 0 , start));
    dist[start] = 0;
    while (!q.empty())
    {
        //for (int i = 0 ; i < v ; i++)
          //  cout << dist[i] << " ";
        //cout << endl;  

        pair <int , int> p = q.top();
        q.pop();
        int d = p.first;
        int vertex = p.second;
        if (d > dist[vertex])
            continue;

        for (int i= 0 ; i < graph[vertex].size() ; i++)
        {
            pair <int , int > p2 = graph[vertex][i];
            int u = p2.first;
            int weight = p2.second;
            if (dist[u] > weight + dist[vertex])
            {
                dist[u] = weight + dist[vertex];
                q.push( make_pair (dist[u] , u) );
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
    int cases = 0;
    while (test--)
    {
        graph.clear();
        cases++;

       
        int v , e;
        cin >> v >> e;
         int start;
        int end;
        cin >> start;
        cin >> end;
        graph.assign (v , vector <pair < int , int>> ());


        for (int i =0  ; i < e ; i++)
        {
            int a , b , wt;
            cin >> a >> b >> wt;
            graph[a].push_back (make_pair (b , wt) );
            graph[b].push_back ( make_pair ( a , wt) );
        }

        for (int i = 0 ; i < v ; i++)
            dist[i] = 1000000000;
        diskstra(start);
        if (dist[end] == 1000000000)
            printf("Case #%d: unreachable\n",cases);
        else
            printf("Case #%d: %lld\n", cases , dist[end]);
    }
    return 0;
}