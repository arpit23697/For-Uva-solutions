#include <bits/stdc++.h>
using namespace std;

int n;
int graph[55][55];

bool visited[55] ;
void dfs (int start)
{
    visited[start] = true;
    for (int i = 0; i < n ; i++)
    {
        if (graph[start][i] == 1)
        {
            if (visited[i] == false)
            dfs(i);
        }
    }
}

int main()
{
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt", "w" , stdout);

    int cases = 0;
    while (1)
    {
        cases++;
        int edges;
        cin >> n >> edges ;
        memset (visited , false , sizeof visited);
        
        for (int i=0 ; i < n ; i++)
        for (int j =0 ; j < n ; j++)
        graph[i][j] = 100000;

        for (int i =0 ; i < n ; i++)
        graph[i][i] = 0;

        if (n ==0 && edges == 0)
        break;


        map <string , int> map1;
        map <int , string > map2;
        pair <map <string , int > :: iterator , bool> ret;
        int temp = 0;

        for (int i=0 ; i < edges ; i++)
        {
            string s , t;
            cin >> s >> t;

            ret = map1.insert(make_pair (s , temp));
            if (ret.second == true)
            {
                temp++;
                map2.insert(make_pair (temp , s));
            }

            ret = map1.insert(make_pair (t , temp));
            if (ret.second == true)
            {
                temp++;
                map2.insert(make_pair (temp , t));
            }
            graph[map1[s]][map1[t]] = 1;
            graph[map1[t]][map1[s]] = 1;
        }
       /* for (map<string, int>::iterator itr =map1.begin(); itr != map1.end(); ++itr)
            cout << itr->first << "   " << itr->second << "\n"; //it is the same as myMap['a']		/access operator is going to work fine

        for (int i= 0 ; i < n ; i++)
        {
            for (int j= 0 ; j < n ; j++)
            cout << graph[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        */
        dfs(0);
        for (int k = 0 ; k < n ; k++)
        for (int i =0 ; i < n ; i++)
        for (int j =0 ; j < n ; j++)
        graph[i][j] = min (graph[i][j] , graph[i][k] + graph[k][j]);
        /*for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << graph[i][j] << " ";
            cout << endl;
        }*/

        bool disconnected = false;
        for (int i =0 ; i < n ; i++)
        if (visited[i] ==false)
        {    
            disconnected = true;
            break;
        }


        if (disconnected)
        {
            printf("Network %d: DISCONNECTED\n\n",cases);
        }
        
        else
        {
            int ans =-1;
            for (int i = 0 ; i < n ; i++)
            for (int j= 0 ; j < n ; j++)
            {
                if (i!=j && graph[i][j] != 100000)
                ans = max (ans , graph[i][j]);
            }
            printf("Network %d: %d\n\n",cases , ans);
        }
    }
    return 0;
}