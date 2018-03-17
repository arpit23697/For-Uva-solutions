#include <bits/stdc++.h>
using namespace std;
int row , col;
int graph[1010][1010];
int dist[1010][1010];

void BFS (pair <int , int > &p)
{
    queue <pair <int , int> > q;
    dist[p.first][p.second] = 0;
    q.push (p);

    while (!q.empty())
    {
        pair <int , int > v = q.front();
        q.pop();
        int x = v.first;
        int y = v.second;

        if (x-1 >= 0 && graph[x-1][y] == 1 && dist[x-1][y] == -1)
        {
            dist[x-1][y] = dist[x][y] + 1;
            q.push (make_pair (x-1 , y));
        }

        if (y-1 >= 0 && graph[x][y-1] == 1 && dist[x][y-1] == -1)
        {
            dist[x][y-1] = dist[x][y] + 1;
            q.push (make_pair (x , y-1));
        }

         if (x+1 < row  && graph[x+1][y] == 1 && dist[x+1][y] == -1)
        {
            dist[x+1][y] = dist[x][y] + 1;
            q.push (make_pair (x+1 , y));
        }

         if (y+1 < col && graph[x][y+1] == 1 && dist[x][y+1] == -1)
        {
            dist[x][y+1] = dist[x][y] + 1;
            q.push (make_pair (x , y+1));
        }

    }
}   
int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    while (1)
    {
        cin >> row >> col;
        if (row == 0 && col == 0)
        break;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                graph[i][j] = 1;
            
        }
        int bombs;
        cin >> bombs;

        for (int i = 0 ; i < bombs ; i++)
        {
            int rowNum ;
            cin >> rowNum;
            int x;
            cin >> x;
            for (int j= 0 ;  j < x ; j++)
            {
                int temp;
                cin >> temp;
                graph[rowNum][temp] = 0;
            }
        }

        
        pair <int , int > source;
        int a , b;
        cin >> a >> b;
        source = make_pair (a , b);
        pair <int , int> destination;
        cin >> a >> b;
        destination = make_pair (a , b);
        memset (dist , -1 , sizeof dist);
        BFS (source);
        
        cout << dist[destination.first][destination.second] << endl;
    
    }
    return 0;
}