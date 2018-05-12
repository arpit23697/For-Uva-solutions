#include <bits/stdc++.h>
using namespace std;
int edges;
int young[26][26];
int aged[26][26];
map <char , int > map1;
map <int , char > map2;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    int cases = 0;

    while (1)
    {
        cases++;
        cin >> edges;
        if (edges == 0)
        break;

        int vertices = 0;
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                aged[i][j] = 1000000;
                young[i][j] = 1000000;
            }
        }
        for (int i= 0 ; i < 26 ; i++)
        {
            aged[i][i] = 0;
            young[i][i] = 0;
        }

        map1.clear();
        map2.clear();
        for (int i= 0; i < edges ; i++)
        {
            char temp , direction , x , y ;
            int we;
            cin >> temp >> direction >> x >> y >> we;
            //if (cases == 100)
            //cout << temp << " " << direction << " " << x << " " << y << " " << we << endl;
            pair<map<char, int>::iterator, bool> ret;

            ret = map1.insert(make_pair(x, vertices));
            if (ret.second == true)
            {
                map2.insert (make_pair (vertices , x));
                vertices++;
            }

            ret = map1.insert(make_pair(y, vertices));
            if (ret.second == true)
            {
                map2.insert (make_pair (vertices , y));
                vertices++;
            }

            if (x == y)
            continue;
            if (temp == 'Y')
            {
                if (direction == 'U')
                    young[map1[x]][map1[y]] = we;
                else if (direction == 'B')
                {
                    young[map1[x]][map1[y]] = we;
                    young[map1[y]][map1[x]] = we;
                }
            }
            else if (temp == 'M')
            {
                if (direction == 'U')
                    aged[map1[x]][map1[y]] = we;
                else if (direction == 'B')
                {
                    aged[map1[x]][map1[y]] = we;
                    aged[map1[y]][map1[x]] = we;
                }
            }

        }
        /*
        for (map <char , int> :: iterator itr = map1.begin() ; itr != map1.end() ; ++itr)
        cout << itr->first << " "<< itr->second << endl;
        cout << endl; 
 

        for (int i= 0 ; i < vertices ; i++)
        {
            for (int j =0 ; j < vertices ; j++)
            cout << young[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
                cout << aged[i][j] << " ";
            cout << endl;
        }*/
        for (int k = 0 ; k < vertices ; k++)
            for (int i =0 ; i < vertices ; i++)
                for (int j =0 ; j < vertices ; j++)
                {
                    young[i][j] = min (young[i][j] , young[i][k] + young[k][j]);
                    aged[i][j] = min (aged[i][j] , aged[i][k] + aged[k][j]);
                }
/*
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
                cout << young[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
                cout << aged[i][j] << " ";
            cout << endl;
        }*/
        int ans;
        char x , y;
        cin >> x >> y;

        
        //if (cases == 100)
        //cout << x << " " << y << endl;
        pair<map<char, int>::iterator, bool> ret;

        ret = map1.insert(make_pair(x, vertices));
        if (ret.second == true)
        {
            if (x == y)
            cout << "0 " << x << endl;
            else
            cout << "You will never meet." << endl;
            continue;
        }
        ret = map1.insert(make_pair(y, vertices));
        if (ret.second == true)
        {
            if (x == y)
            cout << "0 " << x << endl;
            cout << "You will never meet." << endl;
            continue;
        }

        int pos1 = map1[x];
        int pos2 = map1[y];
        if (x == y)
        ans = 0;
        else
        ans  = 1000000;
        
        for (int i= 0 ; i < vertices ; i++)
            ans = min (ans , young[pos1][i] + aged[pos2][i] );

        vector <char> ans2;
        for (int i =0 ; i < vertices ; i++)
        {
            if (young[pos1][i] + aged[pos2][i] == ans)
                ans2.push_back(map2[i]);
        }
        sort (ans2.begin() , ans2.end());
        if (ans == 1000000)
            cout << "You will never meet." << endl;
        else
        {
            cout << ans;
            for (int i= 0 ; i < ans2.size() ; i++)
            cout << " " << ans2[i];
            cout << endl;
        }
    }
    return 0;
}
