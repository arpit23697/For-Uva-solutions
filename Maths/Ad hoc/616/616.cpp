#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    while (1)
    {
        long long int n;
        cin >> n;
        if (n < 0)
        break;

        long long int ans = -1;
        bool possible;
        for (int x = sqrt(n) + 1 ; x > 0 ; x--)
        {
            possible = true;
            long long int temp = n;
            for (int i= 0; i < x ; i++)
            {
                if (temp % x != 1)
                {
                    possible = false;
                    break;
                }
                temp = temp - ( 1 + temp/x);
            }
           // cout << possible << " " << temp << endl;
            if (possible && temp % x == 0)
            {
                ans = x;
                break;
            }
        }
        if (ans != -1)
        printf("%lld coconuts, %lld people and 1 monkey\n" , n , ans );
        else
            printf("%lld coconuts, no solution\n", n);
    }
    return 0;
}