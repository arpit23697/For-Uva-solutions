#include <bits/stdc++.h>
using namespace std;

vector <vector <pair <int ,int > >> graph;
int n;
list <int> cycle;

void Euler (list <int > :: iterator itr , int u)
{
  //  cout << "node : " << u << " : ";
    //for (list<int>::iterator i = cycle.begin(); i != cycle.end(); ++i)
      //  cout << "   " << *i;
    //cout << endl;

    for (int j =0 ; j < graph[u].size() ; j++)
    {
        pair <int , int> p = graph[u][j];
        if (p.second)
        {
            graph[u][j].second = 0;
            p.second = 0;
            for (int k= 0 ; k < graph[p.first].size() ; k++)
            {
                pair <int , int> p1 = graph[p.first][k];
                if (p1.first == u && p1.second)
                {
                    p1.second = 0;
                    graph[p.first][k].second = 0;
                    break;
                }
            }
            Euler (cycle.insert (itr , u) , p.first);
        }
    }
}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt", "w" , stdout);
    int m;
    cin >> n >> m;
    graph.assign (n , vector <pair <int ,int >> ());
    for (int i=0 ; i < m; i++)
    {
        int x , y;
        cin >> x >> y;
        graph[x].push_back(make_pair(y, 1));
        graph[y].push_back(make_pair(x, 1));
    }
/*
    for (int i= 0 ; i < n ; i++)
    {
        cout << i << " ";
        for (int j =0 ; j < graph[i].size() ; j++)
        {
            cout << " " << graph[i][j].first;
        }
        cout << endl;
    }*/
    cycle.clear();
    Euler (cycle.begin() , 0 );
    for (list <int> :: iterator i = cycle.begin() ; i != cycle.end() ; ++i)
    cout << "   " << *i;
    cout << endl;
    return 0;
}