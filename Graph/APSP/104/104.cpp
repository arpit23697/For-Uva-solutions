#include <bits/stdc++.h>
using namespace std;
int n;
double graph[30][30];


int main ()
{
    freopen ("in.txt", "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    while (scanf("%d",&n) == 1)
    {
        for (int i= 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++)
        {
            if (i == j)
            {
                graph[i][j] = 1.0;
                continue;
            }
            cin >> graph[i][j];
        }


        

        int path[n][n][n];
        double solution[n][n][n];
        memset(solution, 0, sizeof solution);
        for (int i=0 ; i < n ; i++)
            for (int j =0 ; j < n ; j++)
            {
                path[i][j][0] = i;
                solution[i][j][0] = graph[i][j];        //having only one edge in the path
            }
        for (int m = 1; m < n ; m++)
        {
            for (int k = 0 ; k < n ; k++)
            {
                for (int i = 0 ; i < n ; i++)
                {
                    for (int j =0; j < n ; j++)
                    {
                        //double temp = solution[i][k][m - 1] * solution[k][j][0];
                        if (solution[i][j][m] < solution[i][k][m - 1] * solution[k][j][0])
                        {
                            solution[i][j][m] = solution[i][k][m - 1] * solution[k][j][0];
                            path[i][j][m] = k;
                        }
                    }
                }
            }
        }

        bool status = false;
        for (int steps =1 ; steps < n ; steps++ )
        {
            for (int i =0 ; i < n ; i++)
            {
                if (solution[i][i][steps] > 1.01)
                {
                   // cout << steps << endl;
                    int seq[steps+1];
                    seq[steps] = path[i][i][steps];
                    for (int j = steps-1 ; j >= 0 ; j--)
                    {
                        seq[j] = path[i][seq[j+1]][j];
                    }
                    for (int j =0 ; j <= steps; j++)
                    cout << seq[j]+1 << " ";
                    cout << seq[0]+1 << endl;
                    status = true;
                    break;
                }
            }
            if (status)
            break;

        }

        if (!status)
        cout << "no arbitrage sequence exists" << endl;

        
    } 
    return 0;
}