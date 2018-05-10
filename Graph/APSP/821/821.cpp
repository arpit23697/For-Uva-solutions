#include <bits/stdc++.h>
using namespace std;

int dist[105][105];


int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);

    int cases = 0;

    while(1)
    {
        map <int , int > myMap;
        cases++;
        int a , b;
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        
        int n = 0;
        
            for (int i =0 ; i < 105 ; i++)
                for (int j =0 ; j < 105 ; j++)
                {
                    if(i == j)
                    dist[i][j] = 0;
                    else
                    dist[i][j] = 10000;  
                }
            
            pair<map<int, int>::iterator, bool> ret;
            ret = myMap.insert(make_pair(a, n));

            if (ret.second == true)
                n++;

            ret = myMap.insert(make_pair(b, n));

            if (ret.second == true)
                n++;

            dist[myMap[a]][myMap[b]] = 1;

            while (1)
            {

                int x , y;
                cin >> x >> y;   
                if (x == 0 && y ==0)
                    break;
            
                ret = myMap.insert(make_pair(x, n));
                if (ret.second == true)
                    n++;
                ret = myMap.insert(make_pair(y, n));
                if (ret.second == true)
                    n++;

                dist[myMap[x]][myMap[y]] = 1;
            }
 
            for (int k = 0 ; k < n ; k++)
            {
                for (int i =0 ; i < n ; i++)
                {
                    for (int j =0  ; j < n ; j++)
                    {
                        dist[i][j] = min (dist[i][j] , dist[i][k] + dist[k][j]);    
                    }
                }
            }

            int total= 0;
            for (int i= 0 ; i < n ; i++)
            for (int j =0 ; j < n ; j++)
            total += dist[i][j];

            double ans = total * 1.0 / (n * (n-1));
            printf("Case %d: average length between pages = %.3lf clicks\n" , cases , ans);
        
    }
    return 0;
}