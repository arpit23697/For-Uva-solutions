#include <bits/stdc++.h>
using namespace std;

vector <vector <pair  <int , int >> > graph;
int n;

vector <int> degrees;
list <int> cycle;

void Euler (list <int> :: iterator itr , int u)
{
    for (int j =0  ; j < graph[u].size() ; j++)
    {
        pair <int , int > v = graph[u][j];
        if (v.second)
        {
            v.second = 0;
            graph[u][j].second = 0;
            for (int k =0  ; k < graph[v.first].size() ; k++)
            {
                pair <int , int > uu = graph[v.first][k];
                if (uu.first == u && uu.second)
                {
                    uu.second == 0;
                    graph[v.first][k].second = 0;
                    break;
                }
            }
        Euler (cycle.insert (itr , u) , v.first);
        }
    }
}




int main ()
{
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int test;
    cin >> test;
    //cout << test << endl;
    int cases = 0;
    while (test--)
    {
    
        cases++;
        graph.clear();
        degrees.clear();

        graph.assign (50 , vector <pair <int , int > >() );
        degrees.assign (50 , 0);        
        cin >> n;
    //    cout << n << endl;
        for (int i=0 ; i < n ; i++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;

          // cout << x << " " << y << endl;

            graph[x].push_back(make_pair (y , 1));
            graph[y].push_back(make_pair (x ,1));
            degrees[x]++;
            degrees[y]++;
        }

        bool possible = true;
        int start = -1;
        for (int i=0 ; i < 50 ; i++)
        {
            if (degrees[i]%2 !=0 )
            {    
                possible = false;
                break;
            }
            else if (degrees[i] != 0 && start == -1)
            start = i;

        }




        cout << "Case #" << cases << endl;
        if (!possible )
            cout << "some beads may be lost" << endl;
        else
        {   
            cycle.clear();
            Euler (cycle.begin() , start);
            vector <int > ans;
            for (list <int > :: iterator itr = cycle.begin() ; itr != cycle.end() ; ++itr)
            {
              //  cout << *itr << endl;    
                ans.push_back(*itr);
            }
            //for (int i= 0 ; i < ans.size() ; i++)
            //cout << ans[i] << endl;

            int size = ans.size();
            for (int i =0 ; i < size-1 ; i++)
            cout << ans[i]+1 << " " << ans[i+1]+1 << endl;
            cout << ans[size-1]+1 << " " << ans[0]+1 << endl;  
        }

         if (test  > 0)
         cout << endl;
    }
    return 0;
}