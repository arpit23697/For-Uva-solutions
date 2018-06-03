#include <bits/stdc++.h>
using namespace std;


vector<vector <pair <int ,long long int >>> graph;
long long int inf = 100000000;
vector <bool> visited;
vector <bool> visited2;
void dfs (int start)
{
    visited[start] = true;
    for (int i= 0 ; i < graph[start].size() ; i++)
    {
        pair <int ,long long int > v = graph[start][i];
        if (visited[v.first] == false)
        dfs (v.first);
    }
}

void dfs2(int start)
{
    visited2[start] = true;
    for (int i = 0; i < graph[start].size(); i++)
    {
        pair<int, long long int> v = graph[start][i];
        if (visited2[v.first] == false)
            dfs2(v.first);
    }
}

int main ()
{
    freopen ("in.txt" , "r" , stdin );
    freopen ("out.txt", "w" , stdout);

    int n;
    int cases =0 ;
    while (scanf ("%d", &n) == 1)
    {
        cases++;
        vector <int> vertex;
        vertex.assign (n , 0);
        for (int i= 0; i < n ; i++)
        cin >> vertex[i];

      //  for (int i= 0; i < n ; i++)
      //  cout << " " << vertex[i] << endl;

        int m;
        graph.assign (n , vector <pair <int , long long int >> ());
        cin >> m;
        for (int i= 0; i < m ; i++)
        {
            int x , y;
            cin >> x >> y;
            x--;
            y--;
            graph[x].push_back (make_pair (y , pow (vertex[y] - vertex[x] , 3) ) );
        }

        /*for (int i= 0 ; i < n ; i++)
        {
            cout << i+1;
            for (int j =0 ; j < graph[i].size() ; j++)
            {
                cout << "(" << graph[i][j].first+1 << "," << graph[i][j].second << ") ";
            }
            cout << endl;
        }*/

        vector <long long int> dist;
        dist.assign (n , inf);
        //for (int i = 0; i < n; i++)
          //  cout << " " << dist[i] ;
            //cout << endl;
        vector <int> pre;
        pre.assign (n , -1);
        if (n > 0)
        dist[0] = 0;

        for (int i= 0 ; i < n -1 ; i++)
        {
            
            for (int u =0 ; u < n ; u++)
            {
                for (int j =0 ; j < graph[u].size() ; j++)
                {
                    pair <int ,long long int > v = graph[u][j];
                    if (dist[v.first] > dist[u] + v.second)
                    {
                        dist[v.first] = dist[u] + v.second;
                        pre[v.first] = u;
                    }
                }
            }
        }

        bool possible = true;
        int index = -1;
      //  for (int i= 0 ; i < n ; i++)
      //  cout << i+1 << " " << pre[i] + 1 << endl;
        for (int i= 0 ; i < n ; i++)
        {
            int u = i;
            for (int j = 0 ; j < graph[u].size() ; j++)
            {
                pair <int ,long long int > v = graph[u][j];
                if (dist[v.first] > dist[u] + v.second)
                {
                    index = v.first;
                    possible = false;
                    break;
                }
            }
        }
        visited.assign (n , false);
        

       //cout << index+1 << endl;
        vector <int> cycle;
        if (!possible)
        {
            int cycleOn = -1;
            vector <int> temp;
            temp.assign (n , 0);
            int current = index;
            while (current != -1)
            {
                if (temp[current] == 0)
                temp[current] = 1;
                if (temp[current] == 1)
                {
                    cycleOn = current;
                    break;
                }
                current = pre[current];

            }
            temp.assign(n, 0);
            current = cycleOn;
          //  cout << cycleOn+1 << endl;
            while (current != -1)
            {
        //       cout << current << " hi " << temp[current] << endl;
                if (temp[current] == 1)
                    break;
                if (temp[current] == 0)
                temp[current] = 1;
                
                cycle.push_back(current);
                current = pre[current];
            }
        }
        visited.assign(n, false);

        for (int i= 0 ; i < cycle.size() ; i++)
        {
            if (visited[cycle[i]] == false)
            dfs (cycle[i]);
        }

       // for (int i= 0 ; i < n ; i++)
      //  cout << " " << visited[i] << " " << dist[i] << endl;

        visited2.assign(n, false);
        if (n > 0)
        dfs2 (0);

      
        int q;
        cout <<"Set #" << cases << endl;
        cin >> q;
        for (int i= 0; i < q ; i++)
        {
            int x;
            cin >> x;
            x--;
        //    cout << " hithere " << x << endl;
            if (!possible)
            {
                if (find (cycle.begin() , cycle.end() , x) != cycle.end())
                cout << "?" << endl;
                else
                {
               //     cout << dist[x] << " " << visited[x] << " " << visited2[x];
                    if (dist[x] < 3 || visited[x] == true)
                    cout << "?" << endl;
                    else if (visited2[x])
                    cout << dist[x] << endl;
                    else 
                    cout  << "?" << endl;
                }
            }
            else
            {
              if (dist[x] < 3 || visited[x] == true)
                cout << "?" << endl;
                else if (visited2[x])
                cout<< dist[x] << endl;
                else 
                cout << "?" << endl;
            }
        }
    }

    return 0;

}