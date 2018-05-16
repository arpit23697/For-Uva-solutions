#include <bits/stdc++.h>
using namespace std;


int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);

    int cases = 0;
    while (1)
    {
        cases++;
        int NC;
        cin >> NC;
        if (NC == 0)
        break;

        int graph[100][100];
        memset (graph , false , sizeof graph);

        map <string , int> map1;
        map <int , string> map2;
        int n =0;
        for (int i= 0 ; i < NC ; i++)
        {
            int event;
            cin >> event;

            bool start = true;
            string last;
            for (int m = 0 ; m < event ; m++)
            {
                string s;
                cin >> s;

                pair <map <string , int > :: iterator , bool> ret;
                ret = map1.insert (make_pair(s , n));

                if (ret.second == true)
                {
                    map2.insert(make_pair (n , s));
                    n++;
                }

                if (start)
                {
                    last = s;
                    start = false;
                    continue;
                }
                else
                {
                    graph[map1[last]][map1[s]] = 1;
                    last = s;
                }
            }

        }
        int NM;
        cin >> NM;
        for (int i =0 ; i < NM ; i++)
        {
            string s , t;
            cin >> s >> t;
            graph[map1[s]][map1[t]] = 1;
        }
  /*      for (map <string , int >:: iterator itr = map1.begin() ; itr != map1.end() ; ++itr)
        cout << itr->first << " " << itr->second << endl;

        for (int i= 0 ; i < n ; i++)
        {
            for (int j=0 ; j < n ; j++)
            cout << graph[i][j] << " ";
            cout << endl;
        }
        cout << endl;
*/
        for (int k = 0 ; k < n ; k++)
        for (int i =0 ; i < n ; i++)
        for (int j = 0; j < n ; j++)
        {
            graph[i][j] |= (graph[i][k] & graph[k][j]);
        }
       /* for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << graph[i][j] << " ";
            cout << endl;
        }
*/
        int ans = 0;
        for (int i =0 ; i < n ; i++)
        for (int j =i+1 ; j < n ; j++)
        {
            if (i!=j && graph[i][j] == false && graph[j][i] == false)
                ans++;
            
        }
        if (ans == 0)
            printf("Case %d, no concurrent events.\n",cases);
        else
        {
            printf("Case %d, %d concurrent events:\n", cases, ans);
            if (ans == 1)
            {
                bool found = false;
                for (int i =0 ; i < n ; i++)
                {
                    for (int j =i+1  ; j<n ; j++)
                    {
                        if (i!=j && graph[i][j] == 0 && graph[j][i] == false)
                        {
                            cout << "(" << map2[i] << "," << map2[j] << ") " << endl;
                            found = true;
                            break;
                        }
                    }
                    if (found)
                    break;
                }
            }
            else if (ans >= 2)
            {
                bool first = false;
                bool second = false;
                for (int i = 0; i < n; i++)
                {
                    for (int j = i+1; j < n; j++)
                    {
                        if (i != j && graph[i][j] == 0 && graph[j][i] == false)
                        {
                            if (!first)
                            {
                                cout << "(" << map2[i] << "," << map2[j] << ") ";
                                first = true;
                            }
                            else
                            {
                                cout << "(" << map2[i] << "," << map2[j] << ") " << endl;
                                second = true;
                                break;
                            }
                        }
                    }
                    if (second)
                        break;
                }
            }
        }
    }
    return 0;
}