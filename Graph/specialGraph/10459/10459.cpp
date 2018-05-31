#include <bits/stdc++.h>
using namespace std;

vector <vector <int > > graph;
int n ;
int source;
vector <int> dist;
vector <int> pre;
int inf = 1000000;

void  bfs (int start)
{
    pre.assign (n , -1);
    dist.assign (n , inf);
    dist[start] = 0;

    queue <int> q;
    q.push(start);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int j= 0 ; j < graph[u].size() ; j++)
        {
            int v = graph[u][j];
            if (dist[v] == inf )
            {
                dist[v] = dist[u] + 1;
                q.push(v);
                pre[v] = u;
            }
        }
    }

}

int main ()
{
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    while (scanf("%d" , &n) == 1)
    {
        graph.assign (n , vector <int> ());
        for (int i= 0 ; i < n ; i++)
        {
            int temp;
            cin >> temp;
            graph[i].assign (temp , 0);
        
            for (int j= 0; j < temp ; j++)
            {
                int x;
                cin >> x;
                x--;
                graph[i][j] = x;
            }
            
        }

        set <int> best;
        set <int> worst;

        bfs (0);
        int ans = -inf;
        for (int i= 0 ; i < n ; i++)
            ans = max (ans , dist[i]);

        int source;

        for (int i= 0 ; i < n ; i++)
        {
            if (ans == dist[i])
            {
                source = i;    
                worst.insert(i+1);
            }
        }
        bfs (source);
        //cout << source << endl;
        //for (int i= 0 ; i < n ; i++)
        //cout << i << " " << dist[i] << endl;
        ans = -inf;
        for (int i = 0; i < n; i++)
            ans = max(ans, dist[i]);

        for (int i = 0; i < n; i++)
        {
            if (ans == dist[i])
            {
                worst.insert(i + 1);
                source = i;
            }
        }
       // cout << ans << endl;
        if (ans % 2 == 0)
        {
            int x = ans/2;
            int current = source;
            while (x--)
            {
                current = pre[current];
            }
            best.insert (current+1);
        }
        else
        {
            int x = ans / 2;
            int current = source;
            while (x--)
            {
                current = pre[current];
            }
            best.insert(current+1);
            current = pre[current];
            best.insert(current+1);
        }

        cout << "Best Roots  :";
        for (set <int> :: iterator itr = best.begin() ; itr != best.end() ; ++itr)
        cout << " " << *itr;
        cout << endl;

        cout << "Worst Roots :";
        for (set<int>::iterator itr = worst.begin(); itr != worst.end(); ++itr)
            cout << " " << *itr;
        cout << endl;
    }    
    return 0;
}