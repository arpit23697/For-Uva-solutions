#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > graph;

char checker[105][105];
bool matrix[105][105];
int total ;
int n;
int e = 1000007;

vector <bool> visited;
vector <int> topological;

void dfs (int start)
{
    visited[start] = true;
    for (int i =0 ; i < graph[start].size() ; i++)
    {
        int v=  graph[start][i];
        if (visited[v] == false)
        dfs(v);
    }
    topological.push_back(start);
}


bool isValid (int i , int j)
{
    if (i >=0 && i < n && j >= 0 && j < n )
    return true;
    return false;
}

int main ()
{
    freopen ("in.txt" , "r " , stdin);
    freopen ("out.txt", "w" , stdout);

    int test;
    cin >> test;
    int cases=0;
    while (test--)
    {
        cases++;

        topological.clear();
        graph.clear();
        cin >> n;

        for (int i =0 ; i < n ; i++)
        for (int j =0 ; j < n ; j++)
        matrix[i][j] = false;

        int source_x , source_y;

        for (int i =0 ; i < n ; i++)
        {
            string str;
            cin >> str;
            for (int j = 0 ; j < n ; j++)
           {
            checker[i][j] = str[j];

            if (str[j] == 'W')
            {
                matrix[i][j] = true;
                source_x = i;
                source_y = j;
                //cout << i << " " << j << endl;
            } 
            else 
            matrix[i][j] = false;
           }
        }
        map <pair <int ,int > , int >map1;
        pair <map <pair <int ,int > , int> :: iterator , bool > ret;
        graph.assign (n*n , vector <int> ());

        //cout << source_x << " " << source_y << endl;
        total = 0;
        map1.insert (make_pair (make_pair (source_x , source_y) , total));
        total++;

        for (int x = source_x ; x >= 0 ; x--)
        {
            for (int y= 0 ; y < n ; y++)
            {
                if (matrix[x][y] == true)
                {
                    ret = map1.insert (make_pair (make_pair (x , y) , total));
                    if (ret.second == true)
                    total++;

                    if (isValid (x-1 , y-1))
                    {
                        if (checker[x-1][y-1] == '.')
                        {
                            ret = map1.insert(make_pair(make_pair(x-1, y-1) , total));
                            if (ret.second == true)
                            total++;

                            matrix[x-1][y-1] = true;
                            graph[map1[make_pair(x,y)]].push_back(map1[make_pair(x-1 , y-1)]);         
                        }
                        else if (checker[x-1][y-1] == 'B')
                        {
                            if (isValid(x-2 , y-2) && checker[x-2][y-2] == '.' )
                            {
                                ret = map1.insert(make_pair(make_pair(x - 2, y - 2), total));
                                if (ret.second == true)
                                    total++;

                                matrix[x - 2][y - 2] = true;
                                graph[map1[make_pair(x, y)]].push_back(map1[make_pair(x - 2, y - 2)]);
                            }
                        }
                    }
                    if (isValid(x - 1, y + 1))
                    {
                        if (checker[x - 1][y + 1] == '.')
                        {
                            ret = map1.insert(make_pair(make_pair(x - 1, y + 1), total));
                            if (ret.second == true)
                                total++;

                            matrix[x - 1][y + 1] = true;
                            graph[map1[make_pair(x, y)]].push_back(map1[make_pair(x - 1, y + 1)]);
                        }
                        else if (checker[x - 1][y + 1] == 'B')
                        {
                            if (isValid(x - 2, y + 2) && checker[x - 2][y + 2] == '.')
                            {
                                ret = map1.insert(make_pair(make_pair(x - 2, y + 2), total));
                                if (ret.second == true)
                                    total++;

                                matrix[x - 2][y + 2] = true;
                                graph[map1[make_pair(x, y)]].push_back(map1[make_pair(x - 2, y + 2)]);
                            }
                        }
                    }
                }
            }
        }


        total++;
        for (int i =0 ; i < n ; i++)
        {
            if (matrix[0][i] == true)
            graph[map1[make_pair(0,i)]].push_back (total-1);
        }

  /*     for (int i= 0 ; i < total ; i++)
        {
            cout << i;
            for (int j =0 ; j < graph[i].size() ; j++)
            cout << " " << graph[i][j];
            cout << endl;
        }
*/
        visited.assign (total , false);
        dfs (0);
      //  for (int i= topological.size() -1 ; i >=0 ; i--)
      //  cout << topological[i] << endl;

        vector <long long int > ways;
        ways.assign (total , 0);
        ways[0] = 1;
        for (int i= topological.size() -1 ; i>=0 ; i--)
        {
            int u = topological[i];
            for (int j = 0 ; j < graph[u].size() ; j++ )
            {
                int v = graph[u][j];
                ways[v] = (ways[v] + ways[u])%e;
            }
        }
        //for (int i= 0 ; i < total ; i++)
        //cout << ways[i] << endl;
        
        printf("Case %d: %lld\n", cases , ways[total-1]);
    }

    return 0;
}