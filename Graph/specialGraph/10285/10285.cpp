#include <bits/stdc++.h>
using namespace std;

int row , col;
int matrix[105][105];

vector <vector <int>> graph;
vector <bool> visited;
vector <int> topological;
int inf = 10000000;

int vertex (int i , int j)
{
    return (i*col +1 + j);
}

bool isValid (int i , int j)
{
    if (i >= 0 && i < row && j >= 0 && j < col)
    return true;

    return false;
}

void dfs (int start)
{
    //cout << start << endl;
    visited[start] = true;
    for (int i= 0 ; i < graph[start].size() ; i++)
    {
        int v = graph[start][i];
        if (visited[v] == false)
        dfs (v);
    }
    topological.push_back(start);
}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    int test;
    cin >> test;
    while(test--)
    {
      //  cout << "==================================" << endl;
        topological.clear();
        graph.clear();
        visited.clear();

        string name;
        cin >> name;

        cin >> row >> col;
        for (int i=0  ; i < row ; i++)
        for (int j=0 ; j < col ; j++)
        cin >> matrix[i][j];
/*        
        cout << name << " " << row << " " << col << endl;
        for (int i= 0; i < row ; i++)
        {
            for (int j=0 ; j < col ; j++)
            cout << matrix[i][j] << " ";
            cout << endl;
        }
*/
/*
        for (int i= 0 ; i < row ; i++)
        {
            for (int j =0 ; j< col ; j++)
            cout << vertex(i , j) << " ";
            cout << endl;
        }*/
        graph.assign ((row * col + 1) , vector <int >());
        
        for (int i= 0 ; i < row ; i++)
        {
            for (int j =0 ;  j < col ; j++)
            {
                
                if (isValid(i-1 , j) && matrix[i][j] > matrix[i-1][j])
                    graph[vertex(i , j)].push_back(vertex(i-1, j));

                if (isValid(i, j-1) && matrix[i][j] > matrix[i][j-1])
                    graph[vertex(i, j)].push_back(vertex(i, j-1));

                if (isValid(i, j+1) && matrix[i][j] > matrix[i][j+1])
                    graph[vertex(i, j)].push_back(vertex(i, j+1));

                if (isValid(i + 1, j) && matrix[i][j] > matrix[i + 1][j])
                    graph[vertex(i, j)].push_back(vertex(i +1, j));
            }
        }
        for (int i= 0 ; i <row ; i++)
        {
            for (int j = 0 ; j < col ; j++)
            {
                if (isValid(i-1 , j) && matrix[i][j] < matrix[i-1][j] )
                continue;

                if (isValid(i, j-1) && matrix[i][j] < matrix[i][j-1])
                    continue;

                if (isValid(i, j+1) && matrix[i][j+1] < matrix[i][j+1])
                    continue;

                if (isValid(i+1, j) && matrix[i][j] < matrix[i+1][j])
                    continue;

                graph[0].push_back(vertex(i, j ));
            }
        }
        
       /* for (int i= 0 ; i < graph.size() ; i++)
        {
            cout << i;
            for (int j =0 ; j < graph[i].size() ; j++)
            cout << " " << graph[i][j];
            cout << endl;
        }*/
       


        visited.assign (row * col + 1 , false);
        dfs(0);

        vector <int> dist;
        dist.assign (row*col+1 , inf);
        dist[0] = 0;

        //cout << "topo " << topological.size() << endl;
        //for (int i=topological.size()-1 ; i>= 0 ; i--)
        //cout << topological[i] << endl;

        for (int i= topological.size()-1 ; i>=0 ; i--)
        {
            int u = topological[i];
            for (int j = 0 ; j < graph[u].size() ; j++)
            {
                int v = graph[u][j];
                int we;
                if (u == 0)
                we = 0;
                else
                we = -1;
                //cout << u << " " << v << endl;
                if (dist[v] > dist[u] + we)
                    dist[v] = dist[u] + we;    
            }
        }

        int ans = inf;
        for (int i= 0 ; i < dist.size() ; i++)
            ans = min (ans , dist[i]);

        cout << name << ": " << -ans+1 << endl;


    }
    return 0;
}