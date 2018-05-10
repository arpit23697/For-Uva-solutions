#include <bits/stdc++.h>
using namespace std;
int rows , cols;
int matrix[55][55];
int currentX;
int currentY;
char direction;
string instructions;

bool update (char step)
{
    if (step == 'L')
    {
        if (direction == 'N')
        direction = 'W';
        else if (direction == 'S')
        direction = 'E';
        else if (direction == 'E')
        direction = 'N';
        else if (direction == 'W')
        direction = 'S';
        return true;
    }
    else if (step == 'R')
    {
        if (direction == 'N')
        direction = 'E';
        else if (direction == 'S')
        direction = 'W';
        else if (direction == 'E')
        direction = 'S';
        else if (direction == 'W')
        direction = 'N';
        return true;
    }
    else
    {
        if (direction == 'N')
        {
            if (currentY+1 < cols)
            currentY ++;
            else 
            return false;
        }
        else if (direction == 'S')
        {
            if (currentY - 1 >= 0)
            currentY--;
            else 
            return false;
        }
        else if (direction == 'W')
        {
            if (currentX-1 >= 0)
            currentX--;
            else 
            return false;
        }
        else if (direction == 'E')
        {
            if (currentX+1 < rows)
            currentX++;
            else 
            return false;
        }
        return true;
    }
}


int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    cin >> rows >> cols;
    rows++;                 //here this is going to store the actual number of rows and cols
    cols++;
    memset (matrix , 0 , sizeof matrix);
    
    while (scanf("%d %d %c", &currentX , &currentY , &direction) != EOF )
    {
        cin >> instructions;
        int size = instructions.size();

        bool flag = false;
        for (int i = 0 ; i < size ; i++)
        {
            //cout << instructions[i] << endl;
            if ( !update(instructions[i]) )
            {
                if (matrix[currentX][currentY] == 0)
                {
                    matrix[currentX][currentY] = 1;
                    printf("%d %d %c LOST\n", currentX , currentY , direction);
                    flag = true;
                    break;
                }
            }    
        }

                    if (flag == false)
                    printf("%d %d %c\n", currentX , currentY , direction);

    } 

    return 0;
}