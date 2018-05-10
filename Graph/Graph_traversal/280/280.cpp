#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > graph;
bool visited[105];
int counter;
int n;

void DFS (int start)
{
   // cout << start << "hi " <<endl;
    for (int i = 0 ; i < graph[start].size() ; i++)
    {
        int v = graph[start][i];
        if (visited[v] == false)
        {   
            visited[v] = true;
            DFS(v);
        }
    }
}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    while (1)
    {
        cin >> n;
        if (n == 0)
        break;

        graph.assign (n , vector<int> ());

        while (1)
        {
            int x;
            int temp;
            cin >> x;
            if (x == 0)
            break;
            
            x--;
            while (1)
            {
                cin >> temp;
                if (temp == 0)
                break;
                temp--;
                graph[x].push_back (temp);
            }
        }

        /*for (int i = 0 ; i < n ; i++)
        {   
            cout << i+1;
            for (int j = 0 ; j < graph[i].size() ; j++)
            cout << " " << graph[i][j]+1;
            cout << endl;
        }*/
        int test;
        cin >> test;
        for (int i= 0 ; i < test ; i++)
        {
            memset (visited , false , sizeof visited);
            int start;
            cin >> start;
            start--;
            counter = 0;
            DFS (start);
            for (int i =0  ; i < n ; i++)
            if (visited[i] == false)
            counter++;
            
            cout << counter;


            for (int j = 0 ; j < n ; j++)
            if (visited[j] == false)
            cout << " " << j+1;

            cout << endl;
        }

    }
    return 0;

}