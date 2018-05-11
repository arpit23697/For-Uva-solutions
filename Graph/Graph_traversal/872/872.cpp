#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> graph;
map <char , int > map1;
map <int , char> map2;
int n;
int indegrees[50];
bool inserted[50];
vector <int> ans;
bool solution;

void solve (int current)
{
    if (current == n)
    {
        solution = true;
        for (int i =0 ; i < n-1 ; i++)
        cout << map2[ans[i]] << " ";
        cout << map2[ans[n-1]] << endl;
    }
    else
    {
        for (int i =0 ; i < n ;i++)
        {
            if (indegrees[i] == 0 && inserted[i] == false)
            {
                ans.push_back(i);
                for (int j = 0 ; j < graph[i].size() ; j++)
                {
                    int v = graph[i][j];
                    indegrees[v]--;
                }
                inserted[i] = true;
                solve(current+1);
                for (int j = 0 ; j < graph[i].size() ; j++)
                {
                    int v = graph[i][j];
                    indegrees[v]++;  
                }
                inserted[i] = false;
                ans.pop_back();
            }
        }
    }

}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);

    int test;
    scanf("%d\n" , &test);
    string s;
    while(test--)
    {
        map1.clear();
        map2.clear();
        graph.clear();
        ans.clear();
        solution = false;

        
        getline(cin , s);
        //cout << s << endl;
        int count = 0;
        vector <char> vec;
        for (int i = 0 ; i < s.size() ; i+=2)
        {
            vec.push_back(s[i]);
            count++;
        }
        sort (vec.begin() , vec.end());
        n = count;

        //for (int i = 0; i < vec.size(); i++)
          //  cout << vec[i] << " ";
        //cout << endl;

        for (int i= 0 ; i < n ; i++ )
        {
            map1.insert (make_pair (vec[i] , i));
            map2.insert (make_pair (i , vec[i]));
            //count++;
        }
    
        //n = count;
        
        //printing the elements
        //for (map <char , int> :: iterator itr = map1.begin () ; itr != map1.end() ; ++itr)
		//cout << itr -> first << "   " << itr -> second << "\n";


        graph.assign (n , vector <int>() );
        memset (indegrees , 0  , sizeof indegrees);
        memset (inserted , false , sizeof inserted);
        getline (cin , s);
        for (int i=0 ; i < s.size() ; i+=4)
        {
            char x = s[i];
            char y = s[i+2];
            graph[map1[x]].push_back (map1[y]);
            indegrees[map1[y]]++;
        }

        solve (0);

        if (!solution)
        cout << "NO" << endl;

        if (test>0)
        cout << endl;
        getline(cin, s);
    }

    return 0;
}