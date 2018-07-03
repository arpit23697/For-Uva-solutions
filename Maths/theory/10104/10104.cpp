#include <bits/stdc++.h>
using namespace std;

long long int x , y , d;
void Euclid (long long int a , long long int b)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        d = a;
        return ; 
    }
    Euclid (b , a%b);
    long long int x1 = y;
    long long int y1 = x - (a/b) * y;
    x = x1;
    y = y1;
}


int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    long long int a, b;
    while (scanf ("%lld %lld" , &a , &b) == 2)
    {
        Euclid(a , b);

        if (x == 0 || y == 0)
        {
        cout << x << " " << y << " " << d << endl;
        continue;
        }
        long long int upper = ceil(1.0 * -x * d / b);
        long long int lower = floor(1.0 * y * d / a);
        
      //  cout << upper << " " << lower << endl;

      
      
      
      
      
        long long int ans_x = x + b/d * lower;
        long long int ans_y = y - a/d * lower;
        long long int minimum = abs(ans_x) + abs(ans_y);
        long long int temp_x , temp_y;
        for (int i = lower ; i <= upper ; i++)
        {
            temp_x = x + b/d * i;
            temp_y = y - a/d * i;
            if (abs(temp_x) + abs(temp_y) < minimum )
            {
                minimum = abs(temp_x) + abs(temp_y);
                ans_x = temp_x;
                ans_y = temp_y;
            }
            else if (abs(temp_x) + abs(temp_y) == minimum && temp_x <= temp_y)
            {
                ans_x = temp_x;
                ans_y = temp_y;
            }

        }

        cout << x << " " << y << " " << d << endl;
    }
    return 0;
}