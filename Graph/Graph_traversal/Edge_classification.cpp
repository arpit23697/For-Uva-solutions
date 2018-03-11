#include <bits/stdc++.h>
using namespace std;

int VISITED = 1;
int UNVISITED = 0;
int EXPLORED = 0;
int n;
int status[1000];
vector <vector <int>> graph;
int parent[1000];



void DFS_Classify (int u)
{
    status[u] = EXPLORED;
    for (int i = 0 ; i < graph[u].size() ; i++)
    {
        int v = graph[u][i];
        if (status[v] == UNVISITED)         //explored -> unvisited
        {
            parent[v] = u;
            DFS_Classify (u);
        }
        else if (status[v] == EXPLORED)     //explored -> explored
        {
            if (v == parent[u])
            cout << "Two way \n";
            else 
            cout << "back edge" << endl;
        }
        else if (status[v] == VISITED)
        {
            cout << "forward edge / cross edge " << endl;
        }
    }
    status[u] == VISITED;
}

int main ()
{
    cin >> n;
    graph.assign (n , vector <int> ());
    int edges;
    for (int i =0  ; i < edges ; i++)
    {
        int a , b;
        cin >> a >> b;
        graph[a].push_back (b);
    }
    memset (status , UNVISITED ,sizeof status);
    memset (parent , -1 , sizeof parent);
    DFS_Classify(0);

    return 0;       //end of the program

}