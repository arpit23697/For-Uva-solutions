#include <bits/stdc++.h>
using namespace std;

map <int , pair <int , int >> map1;
map <pair <int , int > , int> map2;
vector <vector <int> > colors;
int n;
vector <bool> taken;




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
        map1.clear();
        map2.clear();
        colors.clear();
        colors.assign (55 , vector <int >() );        
        cin >> n;
    //    cout << n << endl;
        for (int i=0 ; i < n ; i++)
        {
            int x, y;
            cin >> x >> y;
          // cout << x << " " << y << endl;

            pair <int , int > p = make_pair (x , y);
            map1.insert( make_pair (i , p));
            map2.insert( make_pair (p , i) );
            colors[x].push_back(i);
            colors[y].push_back(i);
            
        }
/*
        for (map<int, pair<int, int>> :: iterator itr = map1.begin() ; itr != map1.end() ; ++itr)
        cout << itr->first << " --- " << itr->second.first << " " << itr->second.second << endl;
 
        cout << " colors " << endl;
        for (int i=1 ; i < 5 ; i++)
        {
            cout << i;
            for (int j = 0 ; j < colors[i].size() ; j++)
            cout << " " << colors[i][j];
            cout << endl;
        }
*/
        bool possible = true;

        taken.assign(n, false);
        
        pair<int, int> p = map1[0];
        vector <pair <int ,int >> ans;
        int x = 0;
        int n1 = n;

        int size = 0;
        while (n--)
        {
            ans.push_back(p);
            size++;
          //  cout << n  << " --- "  <<  p.first << " " << p.second << endl;
            if (n == 0)
            break;
            taken[x] = true;
            int temp = p.second;
            int use = -1;
            int i;
            for (i=0 ; i < colors[temp].size() ; i++)
            {
                int y= colors[temp][i];
                if (taken[y] == false)
                {
                    use = y;
                    break;
                }
            }
            
            if (use == -1)
            {
         //       cout << "hii there" << endl;
                possible = false;
                break;
            }
            else
            {
                vector <int> :: iterator itr = colors[temp].begin() + i;
                colors[temp].erase(itr);
                pair <int , int > p2 = map1[use];
                if (p2.first == temp )
                p = p2;
                else
                p = make_pair (p2.second , p2.first);

                x = use;
            }

        }
     //   cout << "=================== possible " << possible << endl;
      //  for (int i =0 ; i < n1 ; i++)
      //  cout << ans[i].first << " " << ans[i].second << endl;

        if ( ans[0].first == ans[size-1].second)
        possible = true;
        else 
        possible = false;


        cout << "Case #" << cases << endl;
        if (!possible )
            cout << "some beads may be lost" << endl;
        else
        {
            for (int i =0  ; i < size ; i++)
            cout << ans[i].first << " " << ans[i].second << endl;
         }

         if (test  > 0)
         cout << endl;
    }
    return 0;
}