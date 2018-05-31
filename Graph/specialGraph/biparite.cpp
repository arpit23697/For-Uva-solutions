#include <bits/stdc++.h>
using namespace std;

vector <int> match , vis;
vector <vector <int>> graph;

int Aug (int l)
{
    if (vis[l])
    return 0;
    vis[l] = 1;
    for (int j= 0 ; j < graph[l].size() ; j++)
    {
        int r = graph[l][j];
        if (match[r] == -1 || Aug(match[r]))
        {
            match[r] = l;
            return 1;
        }
    }
    return 0;
}

int main ()
{
    int V;
    int MCB = 0;
    match.assign (V , -1);
    for (int l =0 ; l < n ; l++)
    {
        vis.assign (n , 0);
        MCB += Aug(l);
    }
    cout << MCB << endl;
    return 0;
}