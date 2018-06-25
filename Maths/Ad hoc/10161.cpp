#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    long long int n;
    while (1)
    {
        cin >> n;
        if (n == 0)
        break;
        long long int close = floor (sqrt(n));
        long long int currentX = 0;
        long long int currentY = 0;
        if (n%2 == 0)
        {
            currentX = close;
            currentY = 1;
            if (close * close != n)
            {
                currentX += 1;
                if (close * close + currentX <= n)
                    currentY = n - close*close;
                
                else
                {
                    currentY = close + 1;
                    currentX -= n - close*close - currentY;
                }   
            }   
        }
        else
        {
            currentX = 1;
            currentY = close;
            if (close * close != n)
            {
                currentY +=1;
                if (close * close + currentY <= n)
                currentX = n - close * close;
                else
                {
                    currentX = close + 1;
                    currentY -= n-close*close - currentX;
                }
            }
        }
        cout << currentX << " " << currentY << endl;
    }

    return 0;
}