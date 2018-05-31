#include <bits/stdc++.h>
using namespace std;
//too long
// i am not capturing the information about the movement,
int n , k;
int matrix[80][80];
int memo[80][80][7][2][2]; 
                   //first two digits are for the indices
                                        // then for the value of k
int inf = 100000000;
bool possible;

int solve (int x , int y , int left_neg , int left ,int right)
{
    if (x < 0 || y < 0 || x >= n || y >= n || left_neg < 0)
    return -inf;

    if (memo[x][y][left_neg][left][right] != -1)
    return memo[x][y][left_neg][left][right];

    if (x == n - 1 && y == n - 1 && left_neg >= 0 && matrix[x][y] >= 0)
    {
        possible = true;
        return memo[x][y][left_neg][left][right] = matrix[x][y];
    }
    else if (x == n - 1 && y == n - 1 && left_neg >= 1 && matrix[x][y] <  0)
    {
        possible = true;
        return memo[x][y][left_neg][left][right] = matrix[x][y];
    }
    if (left_neg <=  0 && matrix[x][y] < 0)
    {
        return -inf;
    }

    int temp = left_neg;
    if (matrix[x][y] < 0)
        temp -= 1;

    int ans = matrix[x][y];
    
    if (right && !left)
        return memo[x][y][left_neg][left][right] = ans + max (solve (x+1 , y , temp , 1 , 1 ) , solve (x , y+1 , temp , 0 , 1) );

    if (!right && left)
        return memo[x][y][left_neg][left][right] = ans + max(solve(x + 1, y, temp, 1, 1), solve(x, y - 1, temp, 1, 0));
    if (right && left)
        return memo[x][y][left_neg][left][right] = ans + max(solve(x + 1, y, temp, 1, 1), max ( solve (x , y+1 , temp , 0 , 1) , solve (x , y-1 , temp , 1 , 0) ));
}



int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt", "w" , stdout);

    int cases= 0;
    while (1)
    {
        cases++;
        cin >> n >> k;
        if (n ==0 && k == 0)
        break;

        for (int i =0 ; i < n ; i++)
        for (int j =0 ; j < n ; j++)
        {
            cin >> matrix[i][j];
        }
       
        for (int i= 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++)
        for (int m= 0 ; m <= k ; m++)
        for (int l = 0 ; l < 2 ; l++)
        for (int o = 0 ; o < 2 ; o++)
        memo[i][j][m][l][o] = -1;
        
        
        possible = false;        
        int ans = solve (0 , 0 , k , 1 , 1);


        if (!possible)
        printf("Case %d: impossible\n", cases);
        else
        printf("Case %d: %d\n" , cases , ans);
        
    }
    return 0;
}