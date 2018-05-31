#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> graph;
int total;

vector <int> match;
vector <bool> visited;

int Aug (int l)
{
    if (visited[l] == true)
    return 0;
    visited[l] = true;
    for (int j= 0 ;j < graph[l].size() ; j++)
    {
        int r = graph[l][j];
        if (match[r] == -1 || Aug (match[r]))
        {
            match[r] = l;
            return 1;
        }
    }
    return 0;
}

int main ()
{
    freopen ("in.txt", "r" ,stdin);
    freopen ("out.txt" , "w" , stdout);
    int test;
    cin >> test;
    int cases = 0;
    while (test--)
    {
        cases++;
        int n , m;
        cin >> n;

        
        vector <int> A;
        A.assign (n , 0);
        for (int i= 0 ; i < n ; i++)
        {
            cin >> A[i];
            //if (A[i] == 0)
            //cout << "hi"<< endl;
        }
        cin >> m;
        int total = n + m;
        graph.assign (total , vector <int> ());
        for (int i = 0 ; i < m ; i++)
        {
            int x;
            cin >> x;
            
            //cout << "hi2222" << endl;
            for (int j =0 ; j < n ; j++)
            {
                if (A[j] != 0)
                {
                    if (A[j] == 0 || x % A[j] == 0)
                    {
                        graph[j].push_back(i+n);
                        graph[i+n].push_back(j);
                    }
                }
                else if  (A[j] == 0 && x == 0)
                {
                    graph[j].push_back(i + n);
                    graph[i + n].push_back(j);
                }

            }
        }
/*
        for (int i= 0 ; i < total ; i++)
        {
            cout << i;
            for (int j= 0 ; j < graph[i].size() ; j++)
            cout << " " << graph[i][j];
            cout << endl;
        }*/

        int ans =0;
        match.assign (total , -1);
        for (int i= 0 ; i < n ; i++)
        {
            visited.assign (n , false);
            ans += Aug (i);
        }
        printf("Case %d: %d\n" , cases , ans);
    }
    return 0;
}