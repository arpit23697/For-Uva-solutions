#include <bits/stdc++.h>
using namespace std;

int vertexWeight[27];
int indegrees[27];
vector <vector <int>> graph;
int n;

vector <int > topological;
bool visited[30];
int inf = 1000000;

void dfs (int start)
{
   // cout << start << endl;
    visited[start] = true;
    for (int i= 0 ; i < graph[start].size() ; i++)
    {
        int v = graph[start][i];
        if (!visited[v])
        dfs(v);
    }    
    topological.push_back (start);
}

int main ()
{
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w", stdout);
    int test;
    cin >> test;

    cin.ignore();
    cin.ignore();

    map <char , int > map1;
    map <int , char > map2;

    while (test--)
    {
        map1.clear();
        map2.clear();
        memset(vertexWeight, -1, sizeof vertexWeight);
        graph.assign (27 , vector <int >());
        memset (indegrees , 0 , sizeof indegrees);
        topological.clear();
        string line;
        n = 1;
        while(1)
        {
            getline (cin , line);
         //   cout << line << endl;
            if (line.empty())
            break;

            istringstream str(line);
            char x;
            int we;
            str >> x >> we;
            
            pair <map <char , int > :: iterator , bool > ret;
            ret = map1.insert(make_pair (x , n));

            if (ret.second)
            {
                map2.insert(make_pair (n , x));
                n++;
            }

            vertexWeight[map1[x]] = we;
            string temp;
            if (str >> temp)
            {
                for (int i= 0 ; i < temp.size() ; i++)
                {
                    char y = temp[i];
                    ret = map1.insert(make_pair (y , n));
                    if (ret.second)
                    {
                        map2.insert(make_pair(n , y));
                        n++;
                    }
                    graph[map1[y]].push_back(map1[x]);
                    indegrees[map1[x]]++;
                }
            }
        }

  //      for (map <char , int> :: iterator itr = map1.begin() ; itr != map1.end() ; ++itr )
    //  cout << itr->first << " " << itr->second << endl;
/*
        cout << endl;
        for (int i=1 ; i < n ; i++)
        cout << vertexWeight[i] << endl;
        cout << endl;
*/
        for (int i = 1; i < n ; i++)
        {
            if (indegrees[i] == 0)
            graph[0].push_back(i);
        }

      /*  

        for (int i= 0 ; i < n ; i++)
        {
            cout << i;
            for (int j =0 ; j < graph[i].size() ; j++)
            cout << " " << graph[i][j];
            cout << endl;
        }
*/
        memset(visited, false, sizeof visited);
        dfs (0);

        for (int i= 1 ; i < n ; i++ )
        vertexWeight[i] = -vertexWeight[i];
    
        //for (int i= topological.size(); i>=0 ; i--)
        //cout << topological[i] << endl;
        vector <int> dist;
        dist.assign (n , inf);
        
        
        dist[0] = 0;

        for (int i= topological.size() ; i >= 0 ; i--)
        {
            int u = topological[i];
            for (int j = 0 ; j < graph[u].size() ; j++)
            {
                int v = graph[u][j];
                if (dist[v] > dist[u] + vertexWeight[v])
                {
                    dist[v] = dist[u] + vertexWeight[v];
                }
            }
        }   
        for (int i= 0 ; i < n ; i++)
        dist[i] = -dist[i];

        int ans = -10000000;     
        for (int i= 1 ; i < n ; i++)
        {
            ans = max (ans , dist[i]);
        }
        //cout << topological.size() << endl;
        cout << ans << endl;
        if (test > 0)
        cout << endl;
    }
    return 0;
}