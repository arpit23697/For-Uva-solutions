#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> graph;
int n;
vector <int> dist;
void BFS (int start)
{
    queue <int > q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0 ; i < graph[v].size() ; i++)
        {
            int u = graph[v][i];
            if (dist[u] == -1)
            {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    cin >> n;
    graph.assign (n , vector <int>());
    for (int i = 0 ; i < n ; i++)
    {
        int neigbour;
        cin >> neigbour;
        for (int j = 0 ; j < neigbour ; j++)
        {
            int x;
            cin >> x;
            graph[i].push_back (x);
        }
    } 

    int test;
    cin >> test;

    while (test--)
    {
        dist.assign (n , -1);
        int source ;
        cin >> source;
        
        //cout << graph[source][i] << " ";
        //cout << endl;
        if (graph[source].size() == 0)
        {
            cout << "0" << endl;
            continue;
        }
        else
        {
            BFS(source);
            vector <int > ans;
            ans.assign (n , 0);
            for (int i =0 ;  i < n ; i++)
            {
                if (dist[i] != -1)
                ans[dist[i]]++;
            }
            //for (int i= 0  ; i < n ; i++)
           // cout << ans[i] << " ";
           // cout << endl;
            vector <int> :: iterator itr = max_element(ans.begin () , ans.end());
            int index= itr - ans.begin() ;

            if (index == 0)
            index++;
            cout << *itr << " " << index << endl;
        }
    }

    return 0;


}