#include <bits/stdc++.h>
using namespace std;
int row , col;
int matrix[1005][1005];
/*int indices[1005][1005];
*/
int vertex (int i , int j )
{
    return i*col +j;
}

bool isValid (int i , int j)
{
    if (i >= 0 && i < row && j >= 0 && j < col)
    return true;
    return false;
}
int n;
typedef pair<int,int> ii;

vector <int> dist;
int inf = 10000000;

void dijkstra (int x , int y)
{
    ii start = make_pair (x , y);
    dist.assign (n , inf  );
    dist[vertex(x , y) ] = matrix[x][y];

    priority_queue <pair<int,ii> , vector <pair <int ,ii>> , greater <pair <int ,ii>> > pq;
    pq.push (make_pair (matrix[x][y] , make_pair (x , y)));

    while (!pq.empty())
    {
        pair <int , ii> p = pq.top();
        pq.pop();

        int ux = p.second.first;
        int uy = p.second.second;
        int d = p.first;

        if (d > dist[vertex(ux , uy)])
        continue;

        int a , b;
        a = vertex(ux, uy);
        if (isValid (ux-1 , uy))
        {
            b = vertex(ux - 1 , uy);
            if (dist[b] > dist[a] + matrix[ux-1][uy])
            {
                dist[b] = dist[a] + matrix[ux-1][uy];
                pq.push (make_pair (dist[b] , make_pair(ux-1 , uy) ));
            }
        }

        if (isValid(ux, uy-1))
        {
            b = vertex(ux, uy-1);
            if (dist[b] > dist[a] + matrix[ux][uy-1])
            {
                dist[b] = dist[a] + matrix[ux][uy-1];
                pq.push(make_pair(dist[b], make_pair(ux, uy-1)));
            }
        }

        if (isValid(ux, uy+1))
        {
            b = vertex(ux, uy+1);
            if (dist[b] > dist[a] + matrix[ux][uy+1])
            {
                dist[b] = dist[a] + matrix[ux][uy+1];
                pq.push(make_pair(dist[b], make_pair(ux, uy+1)));
            }
        }

        if (isValid(ux + 1, uy))
        {
            b = vertex(ux + 1, uy);
            if (dist[b] > dist[a] + matrix[ux + 1][uy])
            {
                dist[b] = dist[a] + matrix[ux + 1][uy];
                pq.push(make_pair(dist[b], make_pair(ux + 1, uy)));
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
        cin >> row >> col;

        for (int i=0 ; i < row ; i++)
        for (int j =0 ; j < col ; j++)
        cin >> matrix[i][j];
    
        n = row*col;

        dijkstra (0 , 0);
        cout << dist[n-1] << endl;
    
    }
    
    
    return 0;
}