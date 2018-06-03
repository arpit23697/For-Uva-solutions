#include <bits/stdc++.h>
using namespace std;

vector <vector <pair <int ,int > >> graph;
vector <int> vertex;
int n;

vector <int> dist;
int inf = 10000000;

vector <bool> visited;
void dfs (int start)
{
    //if (start < n)
    //{
        visited[start] = true;
        for (int i = 0 ; i < graph[start].size() ; i++)
        {
            pair <int ,int > v= graph[start][i];
            if (visited[v.first] == false && v.first < n)
            dfs (v.first);
        }
    //}
}

vector<bool> visited2;
void dfs2(int start)
{
    //if (start < n)
    //{
    visited2[start] = true;
    for (int i = 0; i < graph[start].size(); i++)
    {
        pair<int, int> v = graph[start][i];
        if (visited2[v.first] == false && v.first < n)
            dfs2(v.first);
    }
    //}
}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" ,stdout);
    int cases= 0;
    while (1)
    {
        cases++;
        cin >> n;
   //  if (cases == 236)
    //  cout << n << endl;
        if (n == -1)
        break;

        vertex.assign (n , 0);
        graph.assign (n , vector <pair <int ,int >> ());

        int source = 0 ;
        int destination = n-1;
        bool flag = true;
        for (int i= 0 ;i < n ; i++)
        {
            
            cin >> vertex[i];

            

            int m;
            cin >> m;
      //      if (cases == 236)
        //     cout << vertex[i] << " " << m;
            for (int j= 0 ; j < m ; j++)
            {
                int x;
                cin >> x;
            //    if (cases == 236)
              //  cout << " " << x;
                x--;
                graph[i].push_back (make_pair (x , -1));
            } 
        //if (cases == 236)
          // cout << endl;
        }
        
        for (int i=0; i < n ; i++)
        {
            int u =i;
            for (int j = 0 ; j < graph[u].size() ; j++)
            {
                pair <int ,int> v = graph[u][j];
                graph[u][j] = make_pair (v.first , vertex[v.first]);
            }
        }

      /*  for (int i = 0 ; i < n ; i++)
        {
            cout << i;
            for (int j =0 ; j < graph[i].size() ; j++)
            {
                pair <int ,int> v = graph[i][j];
                cout << "(," << v.first << "," << v.second << ")";
            }
            cout << endl;
        }
*/
        dist.assign (n , -10000);
        dist[source] = 100;
        vector <int> pre;
        pre.assign (n , -1);

        for (int i= 0 ; i < 2*n-1 ; i++)
        {
            for (int u = 0 ; u < n ; u++)
            {
                for (int j = 0 ; j < graph[u].size() ; j++)
                {
                    pair <int , int> v = graph[u][j];
                    if (v.first < n  && dist[u] + v.second > 0 && dist[v.first] < dist[u] + v.second)
                    {
                        dist[v.first] = dist[u] + v.second;
                        pre[v.first] = u;
                    }
                }
            }
        }

        bool unlimited = false;
        int index = -1;
        for (int i =  0; i < n ; i++)
        {
            int u =i;
            for (int j = 0 ; j < graph[u].size() ; j++)
            {
                pair <int ,int > v = graph[u][j];
                if (v.first < n && dist[u] + v.second > 0 && dist[v.first] < dist[u] + v.second)
                {
                    index = v.first;
                    unlimited = true;
                    break;
                }
            }
            if (unlimited)
            break;
        }

        visited.assign (n , false);
        dfs (source);

        
        vector<int> cycle;
        if (unlimited)
        {
            int cycleOn = -1;
            vector<int> temp;
            temp.assign(n, 0);
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

        visited2.assign (n , false);
        for (int i= 0; i < cycle.size() ; i++)
        if (visited2[i] == false)
        dfs2(cycle[i]);

        if (unlimited == false)
        {
            bool ans = true;
            int current = destination;
            vector <int> path;
            while (current != -1)
            {
                path.push_back(current);
                current = pre[current];
            }
            for (int i=0 ; i < path.size() ; i++)
            if (dist[path[i]] <= 0)
            {
                ans = false;
                break;
            }
     //       cout << ans << " " << visited[destination] << endl;
            if (ans && visited[destination])
            cout << "winnable" << endl;
            else
            cout << "hopeless" << endl;
        }
        else
        {
           // cout << visited[destination] << " " << dist[destination] << endl;
           bool ans = false;
           for (int i= 0 ; i < cycle.size() ; i++)
           if (visited2[cycle[i]] == true)
           {
               ans = true;
           break;
           }
            if (ans && visited2[destination] )
            cout << "winnable" << endl;
            else
            cout << "hopeless" << endl;
        }

    }

    return 0;
}