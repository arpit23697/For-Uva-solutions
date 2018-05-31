#include <bits/stdc++.h>
using namespace std;

vector <vector <int >> graph;
int n;
vector <int> match;
vector <bool> visited;

int Aug (int l)
{
    if (visited[l] == true)
    return 0;
    visited[l] = true;
    for (int j = 0 ; j < graph[l].size() ; j++)
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
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout );
    int test;
    cin >> test;
    int cases =0 ;

    while (test--)
    {
        cases++;
        int nuts , bolts;
        cin >> nuts >> bolts;
        n = nuts+ bolts;

        graph.assign (n , vector <int>());

        for (int i= 0 ; i < nuts ; i++)
        for (int j =0 ; j < bolts ; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                graph[i].push_back(j+nuts);
                graph[j+nuts].push_back(i);
            }
        }

        int ans = 0;
        match.assign (n , -1);
        for (int i= 0 ; i < nuts ; i++)
        {
            visited.assign(nuts , false);
            ans += Aug(i);
        }

        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n" , cases , ans);
    }



    return 0;
}