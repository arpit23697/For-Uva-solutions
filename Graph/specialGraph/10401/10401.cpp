#include <bits/stdc++.h>
using namespace std;

int n;
bool matrix[20][20];
vector <vector <int> > graph;
int total;

vector <bool> visited;
vector <int> topological;


void dfs (int start)
{
    visited[start] = true;
    for (int i=0 ; i < graph[start].size(); i++)
    {
        int v = graph[start][i];
        if (visited[v] == false)
        dfs(v);
    }
    topological.push_back(start);
}

bool isValid (int i , int j)
{
    if (i >= 0 && i<n && j >=0 && j<n)
    return true;
    return false;
}


int vertex (int i , int j)
{
    return i*n + j + 1;
}

int number (char x)
{
    if (x >= '1' && x <= '9')
    return (x - '0' - 1);
    else
    return (x - 'A' + 9);
}

int main ()
{
    freopen ("in.txt", "r" , stdin);
    freopen ("out.txt", "w" , stdout);
    string str;
    while (cin >> str)
    {
        topological.clear();
        visited.clear();
        graph.clear();

        n = str.size();
        for (int i=0  ; i < n ; i++)
        for (int j=0 ; j < n ; j++)
        matrix[i][j] = false;

        for (int i=0 ; i < str.size();  i++)
        {
            if (str[i] == '?')
            continue;

            if (str[i] >= '1' && str[i] <= '9' )
            matrix[i][str[i]- '0' - 1] = true;

            else 
            matrix[i][str[i] - 'A' + 9] = true;
        }

  /*      for (int i= 0 ; i < n ; i++)
        {
            for (int j =0 ; j < n ; j++)
            cout << vertex(i , j) << " ";
            cout << endl;
        }
*/
  
        total = n*n + 2;
        graph.assign (total , vector <int >() );
        if (str[0] == '?')
        {
            for (int i= 0 ; i < n ; i++)
                graph[0].push_back(vertex(i , 0));
            
        }
        else
        {
            int x = number(str[0]);
            graph[0].push_back(vertex(x , 0));
        }

        for (int col = 0 ; col < n-1 ; col++)
        {
            if (str[col] == '?' && str[col+1] == '?')
            {
                for (int i= 0 ; i < n ; i++)
                {
                    for (int j = 0 ; j < n ; j++)
                    {
                        if (abs (j-i) <= 1)
                        continue;
                        else 
                        {
                            graph[vertex(i , col)].push_back(vertex(j , col+1));
                        }
                    }
                }
            }
            else if (str[col] == '?')
            {
                int x= number (str[col+1]);
                for (int i= 0 ; i < n ; i++)
                {
                    if (abs(x-i) <= 1)
                    continue;
                    else
                    graph[vertex(i , col)].push_back(vertex(x , col+1));
                }
            }
            else if (str[col+1] == '?')
            {
                int x = number(str[col]);
                for (int i= 0 ; i < n ; i++)
                {
                    if (abs(x-i) <= 1)
                    continue;
                    else
                    graph[vertex(x , col)].push_back(vertex(i , col+1));
                }
            }
            else
            {
                int x = number(str[col]);
                int y = number(str[col+1]);

                if (abs (x-y) <= 1)
                continue;
                else
                graph[vertex(x , col)].push_back(vertex(y , col+1));
            }
        }

        
            if (str[n-1] == '?')
                for (int i= 0 ; i < n ; i++)
                    graph[vertex(i , n-1)].push_back(total-1);
            else
            {
                int x = number(str[n-1]);
                graph[vertex(x , n-1)].push_back(total-1);
            }
        
        visited.assign (total , false);
        dfs(0);

        if (visited[total-1] == false)
        cout << "0" << endl;
        else
        {
            vector <long long int> ways;
            ways.assign (total , 0);
            ways[0] = 1;

            for (int i= topological.size() -1 ; i >= 0 ; i--)
            {
                int u = topological[i];
                for (int j =0 ; j < graph[u].size() ; j++)
                {
                    int v = graph[u][j];
                    ways[v] += ways[u];
                }
            }
            cout << ways[total-1] << endl;
        }

    }
    return 0;
}