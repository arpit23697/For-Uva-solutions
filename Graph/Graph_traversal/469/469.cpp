#include <bits/stdc++.h>
using namespace std;
vector <string> matrix;
int rows , cols;
int counter;
bool visited[105][105];

bool isRight (int x , int y)
{
    if (x >= 0 && x < rows && y>=0 && y <cols)
    return true;

    return false;
}


void bfs (int x , int y)
{
    queue <pair <int , int >> q;
    visited[x][y] = true;
    q.push(make_pair (x , y));
    counter++;

    while (!q.empty())
    {
        pair <int , int >p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;
       // cout << x << " " << y << endl;
        if (isRight (x-1 , y-1) && matrix[x-1][y-1] == 'W' && visited[x-1][y-1] == false)
        {
            counter++;
            visited[x-1][y-1] = true;
            q.push(make_pair(x-1 , y-1));
        }

        if (isRight (x-1 , y) && matrix[x-1][y] == 'W' && visited[x-1][y] == false)
        {
            counter++;
            visited[x-1][y] = true;
            q.push(make_pair(x-1 , y));
        }
        if (isRight (x-1 , y+1) && matrix[x-1][y+1] == 'W' && visited[x-1][y+1] == false)
        {
            counter++;
            visited[x-1][y+1] = true;
            q.push(make_pair(x-1 , y+1));
        }
        if (isRight (x , y-1) && matrix[x][y-1] == 'W' && visited[x][y-1] == false)
        {
            counter++;
            visited[x][y-1] = true;
            q.push(make_pair(x , y-1));
        }
        if (isRight (x , y+1) && matrix[x][y+1] == 'W' && visited[x][y+1] == false)
        {
            counter++;
            visited[x][y+1] = true;
            q.push(make_pair(x , y+1));
        }
        if (isRight (x+1 , y-1) && matrix[x+1][y-1] == 'W' && visited[x+1][y-1] == false)
        {
            counter++;
            visited[x+1][y-1] = true;
            q.push(make_pair(x+1 , y-1));
        }
        if (isRight (x+1 , y) && matrix[x+1][y] == 'W' && visited[x+1][y] == false)
        {
            counter++;
            visited[x+1][y] = true;
            q.push(make_pair(x+1 , y));
        }
        if (isRight (x+1 , y+1) && matrix[x+1][y+1] == 'W' && visited[x+1][y+1] == false)
        {
            counter++;
            visited[x+1][y+1] = true;
            q.push(make_pair(x+1 , y+1));
        }

    }


}






int main ()
{
    freopen ("in.txt" , "r"  , stdin);
    freopen ("out.txt" , "w" , stdout);

    int test;
    cin >> test;
    string str;
    getline (cin , str);
    getline (cin , str);

    while (test--)
    {   
        matrix.clear();
        while (getline (cin , str))
        {
            if (str[0] != 'L' && str[0] != 'W')
            break;
            else
            matrix.push_back (str);
        }
        rows = matrix.size();
        cols = matrix[0].size();

        istringstream is(str);
        int x , y;
        is >> x >> y;

        memset (visited , false , sizeof visited);
        counter = 0;
        bfs (x-1 , y-1);
        /*for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                cout << visited[i][j] << " ";
            cout << endl;
        }
        */
        cout << counter << endl;
        while (getline ( cin , str))
        {
            if (str.empty())
            break;

            istringstream is (str);
            int x , y;
            is >> x >> y;
            memset (visited , false , sizeof visited);
            counter = 0 ;
            bfs (x-1 , y-1);
          /*  for (int i =0  ; i < rows ; i++)
            {
                for (int j =0 ; j < cols ; j++)
                cout << visited[i][j] << " ";
                cout << endl;
            }
            */
            cout << counter << endl;
        }
        if (test>= 1)
    cout << endl;

    }
    return 0;
}