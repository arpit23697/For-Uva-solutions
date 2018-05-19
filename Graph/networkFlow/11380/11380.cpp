#include <bits/stdc++.h>
using namespace std;

int row , col , P;
int vertexCapacities[35][35];
char matrix[35][35];
int graph[2000][2000];
int n;
int s , t;
int inf = 1000000;
vector <int> pre;
int flow , maxFlow;


bool isValid (int x , int y)
{
    if (x >= 0 && x < row && y >= 0 && y < col)
    return true;

    return false;
}
/*
int calculate_vin (int i , int j)
{return i*row + j + 1;}

int calculate_vout (int i, int j)
{return i*row + j + 2;}*/

void augment (int v , int minWeight)
{
    if (v == s)
    {
        flow = minWeight;
        return;
    }
    else if (pre[v] != -1)
    {
        augment (pre[v] , min (minWeight , graph[pre[v]][v]) );
        graph[pre[v]][v] -= flow;
        graph[v][pre[v]] += flow;
    }
}


int main ()
{
    freopen ("in.txt", "r" , stdin);
    freopen("out.txt", "w" , stdout );
    while (scanf("%d %d %d",&row , &col , &P) == 3)
    {

        map <pair <int , int > ,pair < int , int > > myMap;
        int index=1;
        string str;
        int ans3 = 0;
        for (int i= 0 ; i < row ; i++)
        {
            cin >> str;
            for (int j = 0 ; j < str.size() ; j++)
            {
                myMap.insert (make_pair (make_pair (i , j) ,make_pair ( index , index+1  ) ));
                index+=2;
                matrix[i][j] = str[j];
                if (str[j] == '*')
                vertexCapacities[i][j] = 1;
                else if (str[j] == '.')
                vertexCapacities[i][j] = 1;
                else if (str[j] == '#')
                vertexCapacities[i][j] = 10000;
                else if (str[j] == '@')
                vertexCapacities[i][j] = 10000;
                else if (str[j] == '~')
                vertexCapacities[i][j] = 0;

               // if (vertexCapacities[i][j] == 10000)
               // ans3++;
            } 
        }
        //cout << ans3 <<endl;
  /*      for (int i= 0 ; i < row ; i++)
        {
            for (int j = 0 ; j < col ; j++)
            cout << matrix[i][j] << " ";
            cout << endl;
        }
*/

        n = 2*(row * col) + 2;
        s = 0;
        t = n-1;
        for (int i= 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++)
        graph[i][j] = 0;

    //    for (int i =0 ; i < row ; i++)
      //  {
        //    for (int j = 0 ; j < col ; j++)
         //   cout << i << " " << j << " " <<calculate_vin(i , j) << " " << calculate_vout (i , j) << endl;
       // }
  //    for (map<pair<int, int>, pair<int, int>> :: iterator itr = myMap.begin() ; itr != myMap.end() ; ++itr )
    //    cout << itr->first.first << " " << itr->first.second << " " << itr->second.first << " " << itr->second.second << endl;
            //int ans = 0;

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    pair<int, int> p = myMap[make_pair(i, j)];
                    int vIn = p.first;
                    int vOut = p.second;
                    graph[vIn][vOut] = vertexCapacities[i][j];

                    //setting the relation with the s and t
                    if (matrix[i][j] == '*')
                        graph[s][vIn] = 1;

                    if (matrix[i][j] == '#')
                        graph[vOut][t] = P;

                    if (matrix[i][j] == '~')
                        continue;
                    
                    else
                    {
                        if (isValid(i - 1, j) && matrix[i-1][j] != '~')
                        {
                            pair<int, int> p = myMap[make_pair(i - 1, j)];
                            int v1 = p.first;
                            int v2 = p.second;
                           // ans+=2;
                            
                            graph[v2][vIn] = 10000;
                            graph[vOut][v1] = 10000;
                        }

                        if (isValid(i, j - 1) && matrix[i][j - 1] != '~')
                        {
                            pair<int, int> p = myMap[make_pair(i, j - 1)];
                            int v1 = p.first;
                            int v2 = p.second;
                           // ans+=2;
                            graph[v2][vIn] = 10000;
                            graph[vOut][v1] = 10000;
                        }

                        if (isValid(i, j + 1) && matrix[i][j + 1] != '~')
                        {
                            pair<int, int> p = myMap[make_pair(i, j + 1)];
                            int v1 = p.first;
                            int v2 = p.second;
                           // ans+=2;
                            graph[v2][vIn] = 10000;
                            graph[vOut][v1] = 10000;
                        }
                        if (isValid(i + 1, j) && matrix[i + 1][j] != '~')
                        {
                            pair<int, int> p = myMap[make_pair(i + 1, j)];
                            int v1 = p.first;
                            int v2 = p.second;
                           // ans+=2;
                            graph[v2][vIn] = 10000;
                            graph[vOut][v1] = 10000;
                        }
                    }
                }
            }

/*
        cout << ans << endl;
        int ans2 = 0;
        for (int i =0 ; i < n ; i++ )
        {
            for (int j =0 ; j < n ; j++)
            {
                if (graph[i][j] == 10000)
                ans2++;
                printf("%6d", graph[i][j]);
                
            }
            cout << endl;
        }
        cout << ans2 <<endl;
*/
        maxFlow = 0;
        while (1)
        {
            flow = 0;
            vector <int > dist;
            dist.assign (n , inf);
            dist[s] = 0;

            pre.assign (n , -1);
            queue<int> q;
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
                        q.push(v);
                        dist[v] = dist[u] + 1;
                        pre[v] = u;
                    }
                }
            }
            augment (t , inf);
            if (flow == 0)
            break;
            maxFlow += flow;
        }
        cout << maxFlow << endl;
    }
    return 0;
}