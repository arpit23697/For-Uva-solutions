#include <bits/stdc++.h>
using namespace std;

int graph[100][100];
int machine[100];
int n , edges;

int totalGraph[210][210];
int total;
int s , t;
int flow , maxFlow;
int inf = 1000000;
vector <int> pre;

void augment (int v , int minEdge)
{
    if (v == s)
    {
        flow = minEdge;
        return;
    }
    else if (pre[v] != -1)
    {
        augment (pre[v] , min(minEdge , totalGraph[pre[v]][v]) );
        totalGraph[pre[v]][v] -= flow;
        totalGraph[v][pre[v]] += flow;
    }
}

int cal_yin (int i )
{return 2*i;}
int cal_yout (int i)
{return 2*i + 1;}

int main ()
{
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt", "w" , stdout);
    while (1)
    {
        cin >> n >> edges;
        if (n == 0 && edges == 0)
        break;

        for (int i= 0 ; i < n ; i++)
        machine[i] = 0;

        for (int i =0 ; i < n ; i++) 
        for (int j =0 ; j < n ; j++)
        graph[i][j] = 0;

        for (int i = 0 ; i < n-2; i++)
        {
            int x , we;
            cin >> x >> we;
            
            x--;
            machine[x] = we;
        }

        for (int i= 0 ; i < edges ; i++)
        {
            int a , b , we;
            cin >> a >> b >> we;

            a--;
            b--;
            graph[a][b] = we;
            graph[b][a] = we;
        }

       // for (int i= 0 ; i < n ; i++)
       // cout << machine[i] << " ";
       // cout << endl;
/*
        for (int i= 0 ; i < n ; i++)
        {
            for (int j=0 ; j < n ; j++)
            cout << graph[i][j] << " ";
            cout << endl;
        }*/

        total = 2*n;
        s = cal_yout(0) ;
        t = total - 2;
        
        for (int i= 0 ; i < total ; i++)
        for (int j =0 ; j < total ; j++)
        totalGraph[i][j] = 0;

        for (int i= 0 ; i < n ; i++)
        {
            int yIn = cal_yin(i);
            int yOut = cal_yout(i);
            totalGraph[yIn][yOut] = machine[i];
            for (int j = 0 ; j < n ; j++)
            {
                int y = cal_yin(j);
                totalGraph[yOut][y] = graph[i][j];
            }
            for (int j =0 ; j < n ; j++)
            {
                int y= cal_yout(j);
                totalGraph[y][yIn] = graph[j][i];   
            }
            
        }

  /*      cout << " ===================== " << endl;
        for (int i = 0; i < total; i++)
        {
            for (int j = 0; j < total; j++)
                cout << totalGraph[i][j] << " ";
            cout << endl;
        }
        cout << "============================" << endl;
        for (int i= 0 ; i < n ; i++)
        cout << i << " " << cal_yin(i) << " " << cal_yout(i) << endl;
*/
        maxFlow = 0;
        while (1)
        {
            flow = 0;
            vector <int> dist;
            dist.assign (total , inf);
            dist[s] = 0;

            pre.assign (total , -1);
            queue <int> q;
            q.push(s);

            while (!q.empty())
            {
                int u = q.front();
                q.pop();

                if (u == t)
                break;

               for (int v= 0 ; v < total ; v++)
                {
                    if (totalGraph[u][v] > 0 && dist[v] == inf)
                    {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                        pre[v] = u;
                    }
                }
            }
            //cout << flow << endl;
            augment (t , inf);
  //          cout << flow << endl;
            if (flow == 0)
            break;
            maxFlow += flow;
        }
        cout << maxFlow << endl;

    }
    return 0;
}