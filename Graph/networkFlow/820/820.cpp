#include <bits/stdc++.h>
using namespace std;

long long int graph[105][105];
long long int n;
long long int s , t;
long long int edges;
long long int maxFlow , flow;
vector <int> pre;

long long int inf = 10000000000;

void augment (int v ,long long int minEdge)
{
    if (v == s)
    {
        flow = minEdge;
        return;
    }
    
    else if (pre[v] != -1)
    {
        augment (pre[v] , min (minEdge , graph[pre[v]][v] ));
        graph[pre[v]][v] -= flow;
        graph[v][pre[v]] += flow;
    }
    
}
void print ()
{
    for (int i =0 ; i < n ; i++)
    {
        for (int j =0 ; j < n ; j++)
        cout << graph[i][j] << " ";
        cout << endl;
    }
    cout <<endl;
}

int main ()
{
    freopen("in.txt", "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int cases = 0;
    while (1)
    {
        cases++;
        cin >> n;
        if (n == 0)
        break;

        cin >> s >> t >> edges;
        s--;
        t--;
        for (int i= 0 ; i < n ; i++)
        for (int j =0 ; j < n ; j++)
        graph[i][j] = 0;

        for (int i= 0 ; i < edges ; i++)
        {
            int x , y , we;
            cin >> x >> y >> we;
            x--;
            y--;
            graph[x][y] += we;
            graph[y][x] += we;
        }
        maxFlow = 0;
        while (1)
        {
            flow =0;
            vector <long long int> dist;
            dist.assign (n , inf);
            dist[s] = 0;

            pre.assign (n , -1);
            queue <int> q;
            q.push(s);

            while (!q.empty())
            {
                int u = q.front();
                q.pop();

                if (u == t)
                break;

                for (int v = 0 ; v < n ; v++)
                {
                    if (graph[u][v] > 0 && dist[v] == inf)
                    {
                        pre[v] = u;
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
            /*
            cout << s << " " << t << endl;
            for (int i =0 ; i < n ; i++)
            cout << pre[i] << " " << i << endl;
            cout << endl;
            cout << flow << endl << endl;
            print();*/
            augment (t , inf);
            //print();
            //cout << maxFlow << endl;
            if (flow == 0)
            break;
            maxFlow += flow;
        }

        printf("Network %d\n", cases);
        printf("The bandwidth is %lld.\n\n", maxFlow);


    }
    return 0;
}