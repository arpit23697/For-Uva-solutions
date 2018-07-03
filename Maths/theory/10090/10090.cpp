#include <bits/stdc++.h>
using namespace std;

long long int gcd (long long int a , long long int b)
{
    if (b == 0)
    return a;
    return gcd (b , a%b);
}

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
    while (1)
    {
        long long int a , b ,c , cost1 , cost2;
        cin >> c;               //this is n
        if (c == 0)
        break;
        cin >> cost1 >> a >> cost2 >> b;
        bool flipped = false;
        if (1.0 * cost1/a > 1.0 * cost2 / b)
        {
            swap(cost1 , cost2);
            swap (a , b);
            flipped = true;
        }

        long long int temp = gcd (a , b);
        if (c % temp != 0 )
        {
            cout << "failed" << endl;
            continue;
        }
        Euclid (a , b);


        x = x * (c / temp);             // so x = x0 + (b / d) * n;
        y = y * (c / temp);             // so y = y0 - (a / d) * n;

 
        long long int n1 =ceil( 1.0 * -x * d / b) ; // min
        long long int n2 = floor( 1.0 * y *  d/ a );


        if (n1 > n2)
        {
            cout << "failed" << endl;
            continue;
        }

        long long int ans_x = x + (b / d) * n2;
        long long int ans_y = y - (a / d) * n2;


        if (ans_x >= 0 && ans_y >= 0)
        if (!flipped)
        cout << ans_x << " " << ans_y << endl;
        else
        cout << ans_y << " " << ans_x << endl;
        else 
        cout << "failed" << endl;
    }
    return 0;
}