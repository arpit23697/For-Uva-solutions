#include <bits/stdc++.h>
using namespace std;
map <string , int> myMap;
map <int , string> myMap2;
vector <vector <int> > graph;
int n;
long long int dist[205];
long long int inf = 1000000000;

void BFS (long long int start)
{
    queue <long long int >q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
       long long  int v = q.front();
        q.pop();
        for (int i = 0 ; i < graph[v].size() ; i++)
        {
            long long int u= graph[v][i];
            if (dist[u] == 100000)
            {
                dist[u] = dist[v] + 1;
                q.push (u); 
            }
        }
    }
}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    
    int test;
    cin >> test;
    while (test--)
    {
        myMap.clear();
        myMap2.clear();
        graph.clear();
        string temp;
        int counter = 0;
        while (1)
        {
            cin >> temp;
            if (temp == "*")
            break;

            myMap.insert (make_pair (temp , counter));
            myMap2.insert (make_pair (counter , temp));
            counter++;
        }
/*
        for (map <string , int> :: iterator itr = myMap.begin() ; itr != myMap.end() ; ++itr)
        {
            pair <string , int> p = *itr;
            cout << p.first << " " << p.second << endl;
        }

        for (map<int , string>::iterator itr = myMap2.begin(); itr != myMap2.end(); ++itr)
        {
            pair<int , string> p = *itr;
            cout << p.first << " " << p.second << endl;
        }
*/
        n = counter;
        graph.assign (n , vector <int >());
        cin.ignore();

        for (int i =0  ; i < n ; i++)
        {
            for (int j = i+1 ; j < n ; j++)
            {
                string x = myMap2[i];
                string y = myMap2[j];

                bool edge = false;
                int count = 0;
                if (x.size() != y.size())
                    continue;

                for (int k = 0 ; k < x.size() ; k++)
                if (x[k] != y[k])
                count++;

                if (count == 1)
                edge = true;

                if (edge)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);   
                }
            }
        }

        string line;
        while (getline(cin , line) && line != "")
        {
            stringstream ss(line);
            string x , y;
            ss >> x >> y;

            for (int i= 0 ; i < n ; i++)
                dist[i] = 100000;
            long long int source = myMap[x];
            long long int destination = myMap[y];


            BFS(source);
            cout << x << " " << y << " " << dist[destination] << endl;
        }
        if (test != 0)
        cout << endl;

        
    }
    return 0;
}