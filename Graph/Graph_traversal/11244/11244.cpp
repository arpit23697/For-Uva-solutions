#include <bits/stdc++.h>
using namespace std;
int row , col;

bool valid (int x , int y)
{
    if (x >= 0 && x < row && y >= 0 && y < col)
    return true;

    return false;
}


int main ()
{
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt", "w", stdout);

    while (1)
    {
        cin >> row >> col;
        if (row == 0 && col == 0)
        break;

        char matrix[row][col];
        for (int i =0 ; i < row ; i++)
        {
            string temp;
            cin >> temp;
            for (int j =0 ; j < temp.size() ; j++)
            matrix[i][j] = temp[j];
        }

        int count = 0;
        for (int i= 0 ; i < row ; i++)
        {
            bool star;
            for (int j =0 ; j < col ; j++ )
            {
                if (matrix[i][j] == '*')
                star = true;
                else
                {
                    star = false;
                    continue;
                }

                    if (valid(i-1 , j-1) && matrix[i-1][j-1] == '*' )
                    {
                        star = false;
                        continue;
                    }

                    if (valid(i-1 , j) && matrix[i-1][j] == '*' )
                    {
                        star = false;
                        continue;
                    }

                    if (valid(i-1 , j+1) && matrix[i-1][j+1] == '*' )
                    {
                        star = false;
                        continue;
                    }
                    if (valid(i, j-1) && matrix[i][j-1] == '*' )
                    {
                        star = false;
                        continue;
                    }
                    if (valid(i, j+1) && matrix[i][j+1] == '*' )
                    {
                        star = false;
                        continue;
                    }
                    if (valid(i+1 , j-1) && matrix[i+1][j-1] == '*' )
                    {
                        star = false;
                        continue;
                    }
                    if (valid(i+1 , j) && matrix[i+1][j] == '*' )
                    {
                        star = false;
                        continue;
                    }
                    if (valid(i+1 , j+1) && matrix[i+1][j+1] == '*' )
                    {
                        star = false;
                        continue;
                    }
                    if (star)
                        count++;
            }
            
    
        }
        cout << count << endl;

    }
    return 0;
}