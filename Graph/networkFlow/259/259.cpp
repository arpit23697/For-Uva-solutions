#include <bits/stdc++.h>
using namespace std;

int graph[38][38];
int n = 38;

int s , t , flow , maxFlow;
int inf = 100000;

vector <int> pre;
void augment(int v , int minEdge)
{
    if (v == s)
    {
        flow = minEdge;
        return;
    }
    else if (pre[v] != -1)
    {
        augment ( pre[v] , min (minEdge , graph[pre[v]][v] ) );
        graph[pre[v]][v] -= flow;
        graph[v][pre[v]] += flow;

    }
}

int main ()
{
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    while(1)
    {
        for (int i=0 ; i < n ; i++)
        for (int j =0 ; j < n ; j++)
        graph[i][j] = 0;

        string str;
        bool done = false;
        while (1)
        {
            if (!getline (cin , str))
            {
                done = true;
                break;
            }

            //cout << str << endl;
            if (str.empty())
                break;

        
            int x = str[0]-'A'+1;
            int users = str[1] - '0';
            graph[0][x] += users;

            for (int i= 3 ; i < str.size()-1 ; i++)
            {
                int y = str[i] - '0';
                y += 27;
                graph[x][y] = inf;
            }
        }


        int totalApplication = 0;
        for  (int i = 1 ; i < 27 ; i++)
        totalApplication += graph[0][i];

        for (int i = 27 ; i < n-1 ; i++)
        graph[i][n-1] = 1;

        s = 0;
        t = n-1;

        maxFlow =0;
        while (1)
        {
            flow = 0;
            vector <int> dist;
            dist.assign (n , inf);
            dist[s] = 0;

            pre.assign (n , -1); 
            queue <int>q;
            q.push(s);

            while(!q.empty())
            {
                int u = q.front();
                q.pop();

                if (u == t)
                break;

                for (int v = 0 ; v < n ; v++)
                {
                    if (graph[u][v] > 0 && dist[v] == inf)
                    {
                        dist[v] = dist[u]+1;
                        pre[v] = u;
                        q.push(v);
                    }
                }
            }
            augment (t , inf);
            if (flow == 0)
            break;
            maxFlow += flow;
        }
        //cout << maxFlow <<endl;

        if (maxFlow != totalApplication)
        cout << "!" << endl;
        else
        {
            for (int i= 27 ; i <= 36 ; i++)
            {
                bool done = false;
                for (int j =1 ; j < 27 ; j++ )
                if(graph[i][j] == 1)
                {
                    char x = 'A' + j - 1;
                    cout << x;
                    done = true;
                    break;
                }

                if (!done)
                cout << "_";
            }
            cout << endl;
        }
        if (done)
            break;
    } 
    return 0; 
}