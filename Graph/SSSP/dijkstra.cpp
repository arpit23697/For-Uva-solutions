#include <bits/stdc++.h>
using namespace std;
//this one contains the code of the dijkstra function

vector <vector <pair <int , int >>> graph;
vector <int> dist;
int inf = 1000000;


void dijkstra (int start)
{
    dist.assign (n , inf);
    dist[start] = 0;

    //first element determines the data type , second one the container type and the last one the comparator function
    priority_queue (pair <int , int > , vector <pair <int , int >> , greater <pair <int ,int >> ) pq;
    pq.push(make_pair (0 , start));

    while (!pq.empty())
    {
        pair <int , int > p = pq.front();
        pq.pop();

        int u = p.second;
        int d = p.first;
        if (d > dist[u] )
        continue;
        for (int i =0 ; i < graph[u].size() ; i++)
        {
            pair <int , int > v = graph[u][i];
            if (dist[v.first] > dist[u] + v.second)
            {
                dist[v.first] = dist[u] + v.second;
                pq.push(make_pair (dist[u] + v.second , v.first));
            }
        }
    }    
}



int main ()
{

}