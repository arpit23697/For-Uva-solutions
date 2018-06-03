#include<bits/stdc++.h>
using namespace std;

int total;
vector <int> times;
vector <vector <pair <int ,int >>> graph;

vector <int> dist;
int inf = 100000000;

void dijkstra (int start)
{
    dist.assign (total , inf);
    dist[start] = 0;

    priority_queue <pair <int ,int > , vector <pair <int ,int >> , greater <pair <int , int>> > pq;
    pq.push(make_pair (0 ,start));

    while (!pq.empty())
    {
        pair <int , int > p = pq.top();
        pq.pop();
        int u = p.second;
        int d = p.first;

        if (d > dist[u])
        continue;

        for (int i= 0; i < graph[u].size() ; i++)
        {
            pair <int , int> v = graph[u][i];
            if (dist[v.first] > dist[u] + v.second)
            {
                dist[v.first] = dist[u] + v.second;
                pq.push(make_pair (dist[v.first] , v.first));
            }
        }
    }
}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    int n , k;
    while (scanf ("%d %d" , &n ,&k ) == 2)
    {
        //cout << n << " ---- " << k << endl;
        k++;
        times.assign (n , 0);
        for (int i =0 ; i < n-1 ; i++)
        cin >> times[i];
        scanf ("%d\n", &times[n-1]);
/*
        for (int i=0 ; i < n ; i++)
        cout << times[i] << " ";
        cout << endl;*/  
        //cin.ignore ('\n');
        total = n*100 + 2;
        graph.assign (total , vector <pair <int ,int >>());
        
        for (int i=0 ; i < n ; i++)
        {
            string str;
            getline (cin , str);
            
           // cout << str << " hiii" << endl;
            istringstream is (str);
            vector <int> temp;
            int x;
            while (is >> x)
            {
                x++;
                temp.push_back (x);
            }
            int a, b ,we;
            for (int j = 0 ; j < temp.size() ; j++)
            {
                for (int k =j+1 ; k < temp.size() ; k++)
                {
                    a = i*100 + temp[j];
                    b = i*100 + temp[k];
                    we = abs (temp[j] - temp[k] ) * times[i]; 
                    graph[a].push_back (make_pair (b , we));
                    graph[b].push_back (make_pair (a , we));
                }
            }
        }

        if (n >= 2)
        {
            int a , b , we;
            for (int i= 1 ; i <= 100 ; i++)
            {
                for (int j =0 ; j < n ; j++)
                {
                    for (int k = j+1 ; k < n ; k++)
                    {
                        a = j*100 + i;
                        b = k*100 + i;
                        we = 60;
                        graph[a].push_back(make_pair(b , we) );
                        graph[b].push_back(make_pair(a , we) );
                    }
                }
            }
        }

        for (int i =0 ; i < n ; i++)
        {
            graph[0].push_back (make_pair (1 + i*100 , 0));
            graph[1 + i*100].push_back(make_pair (0 , 0));
            graph[k + i*100].push_back(make_pair (total-1 , 0));
            graph[total - 1].push_back(make_pair (k + i*100 , 0));
        }

        dijkstra(0);
        if (dist[total - 1] == inf)
        cout << "IMPOSSIBLE" << endl;
        else
        cout << dist[total-1] << endl;
    }    

    return 0;
}