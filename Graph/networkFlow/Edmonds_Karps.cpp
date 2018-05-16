#include <bits/stdc++.h>
using namespace std;
int n;
int graph[n][n];
int s , t , maxFlow , flow;
vector <int> p;

int inf = 100000;

void augment (int v , int minEdge)
{
    if (s == v) 
    {
        f = minEdge;
        return;
    }
    else if (p[v] != -1) 
    {
        augment (p[v] , min (minEdge , graph[p[v]][v] );
        graph[p[v]][v] -= f;
        graph[v][p[v]] += f;
    }
}

int main ()
{
    maxFlow = 0;
    while (1)
    {
        flow = 0;
        vector <int> dist;
        dist.assign (n , inf);
        dist[s] = 0;

        queue <int> q;
        q.push(s);

        p.assign (n , -1);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (u == t)             //if we reach the sink s then immediately break it.
            break;

            for (int v =0 ; v < n ; v++)
            {
                if (graph[u][v] > 0 && dist[v] == inf)
                {
                    dist[v] = dist[u] + 1;
                    p[v] =u;
                    q.push(v);
                }
            }
        }
        augment (t , inf);
        if (flow ==0)
        break;
        maxFlow += flow;

    }
    return 0;
}