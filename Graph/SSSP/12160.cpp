#include <bits/stdc++.h>
using namespace std;
int start , destination , R;
vector <int> edges;

vector <int> dist;
vector <bool> visited;

int n = 10000;
int inf = 1000000;

void BFS (int start)
{
    dist.assign (n , inf);
    dist[start] = 0;
    queue <int> q;
    q.push(start);

    visited.assign (n , false);
    visited[start] = true;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        if (v == destination)
        break;

        for (int i= 0; i < R ; i++)
        {
            int u = (v + edges[i])%n;
            if (visited[u] == false)
            {
                visited[u] = true;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

}


int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    int cases = 0;

    while (1)
    {
        cases++;
        edges.clear();

        cin >> start >> destination >> R;
        if (start == 0 && destination == 0 && R == 0)
        break;
        //cout << start << " " << destination << " " << R << endl;
        for (int i =0 ; i < R ; i++)
        {
            int x;
            cin >> x;
            edges.push_back (x);
        }
        sort (edges.begin() , edges.end() , greater <int> ());
        //for (int i =0 ; i < R ; i++)
        //cout << edges[i] << " " << endl;
        BFS (start);
        if (dist[destination] == inf)
            printf("Case %d: Permanently Locked\n", cases);
            else
                printf("Case %d: %d\n", cases , dist[destination]);

    }
    return 0;
}