#include <bits/stdc++.h>
using namespace std;

int row , col ;
char matrix[45][15];
map <pair <int ,int> , int > map1;

//map <int , pair <int ,int >> map2;
int Left , Right;               //odd is on the Left
                                //even is one the Right

vector <vector <int>> graph;


bool isValid (int i , int j)
{
    if (i >= 0 && i < row && j >= 0 && j < col)
    return true;
    return false;
}
vector <bool> visited;
vector <int> match;

int Aug (int l)
{
    if (visited[l] == true)
    return 0;
    visited[l] = true;
    for (int j =0 ; j < graph[l].size() ; j++)
    {
        int r = graph[l][j];
        if (match[r] == -1 || Aug(match[r]) )
        {
            match[r] = l;
            return 1;
        }
    }
    return 0;
}


int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);

    int test;
    cin >> test;
    while (test--)
    {
        map1.clear();
        cin >> row >> col;
        Left = 0;
        Right = 0;
        int n = 0;
        for (int i =0 ; i < row ; i++)
        {
            string str;
            cin >> str;
            for (int j =0 ; j < col ; j++)
            {
                matrix[i][j] = str[j];
                if (str[j] == '*')
                {
                    if ((i+j)%2 != 0)       //sum is odd
                    {
                        map1.insert (make_pair (make_pair (i , j) , n));
                        n++;
                    }      
                }
            }
        }

        Left = n;
        for (int i= 0 ; i < row ; i++)
        for (int j =0 ; j < col ; j++)
        {   
            if (matrix[i][j] == '*')
            {
                if ((i+j)%2 == 0)
                {
                    map1.insert (make_pair (make_pair (i, j) , n));
                    n++;
                    Right++;
                }
            }
        }

       /* cout << Left << " " << Right << " " << n << endl;
        for (map<pair<int, int>, int> :: iterator itr = map1.begin() ; itr != map1.end() ; ++itr)
            cout << itr->first.first << " " << itr->first.second << " --- " << itr->second << endl;
*/
            graph.assign(n, vector<int>());

        //now making the graph
        pair<int, int> p;
        pair <int , int >p1;
        for (int i= 0 ; i < row ; i++)
        {
            for (int j = 0 ; j < col ; j++)
            {

                if (matrix[i][j] == '*')
                {
                    p = make_pair(i , j);
                    if (isValid (i-1 , j) && matrix[i-1][j] == '*')
                    {
                        p1 = make_pair (i-1,j);
                        graph[map1[p]].push_back(map1[p1]);
                       // graph[map1[p1]].push_back(map1[p]);
                    }

                    if (isValid(i, j-1) && matrix[i][j-1] == '*')
                    {
                        p1 = make_pair(i, j-1);
                        graph[map1[p]].push_back(map1[p1]);
                       // graph[map1[p1]].push_back(map1[p]);
                    }

                    if (isValid(i, j+1) && matrix[i][j+1] == '*')
                    {
                        p1 = make_pair(i, j+1);
                        graph[map1[p]].push_back(map1[p1]);
                       // graph[map1[p1]].push_back(map1[p]);
                    }

                    if (isValid(i + 1, j) && matrix[i + 1][j] == '*')
                    {
                        p1 = make_pair(i + 1, j);
                        graph[map1[p]].push_back(map1[p1]);
                       // graph[map1[p1]].push_back(map1[p]);
                    }
                }
            }
        }
/*
        for (int i= 0 ; i < n ; i++)
        {
            cout << i;
            for (int j= 0 ; j < graph[i].size() ; j++)
            cout << " " << graph[i][j];
            cout << endl;
        }
*/
        int ans = 0;
        match.assign (n , -1);
        for (int i =0 ; i < Left ; i++)
        {
            visited.assign ( Left , false);
            ans += Aug (i);
        }
        int temp = n - 2*ans;
        cout << ans+temp << endl;


    }

    return 0;
}