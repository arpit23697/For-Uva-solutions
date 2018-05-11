#include <bits/stdc++.h>
using namespace std;
int n;
vector <vector <int>> graph;
bool visited[100];

void DFS (int start)
{
    visited[start] = true;
    for (int i= 0 ; i < graph[start].size() ; i++)
    {
        int v = graph[start][i];
        if (visited[v] == false)
        DFS (v);
    }
}

int main ()
{
    freopen ("in.txt" , "r" , stdin );
    freopen ("out.txt", "w" , stdout);
    int test;
    scanf("%d\n",&test);
    string s;
    while (test--)
    {
        getline (cin , s);

        n = s[0] - 'A' + 1;
        graph.assign (n , vector <int >() );
        while(1)
        {
            
            if (!getline(cin , s) || s.empty())
            break;

            int x1 = s[0]-'A';
            int x2 = s[1]-'A';
            graph[x1].push_back (x2);
            graph[x2].push_back(x1);
        }
        memset (visited , false , sizeof visited);
        int components = 0;
        for (int i =0 ; i < n ; i++)
        {
            if (visited[i] ==false)
            {
                components++;
                DFS(i);
            }
        }
        cout << components <<  endl;
        if ( test > 0)
        cout << endl;
    }
    return 0;
}