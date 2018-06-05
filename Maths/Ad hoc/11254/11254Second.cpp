#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    while (1)
    {
        long long int n;
        cin >> n;
        if (n == -1)
            break;
        bool found = false;
        long long int first, second, terms, sum;
        long long int a, b, c;
        for (terms = sqrt (2 * n); terms >=  1; terms--)
        {
            first = ((( 2 * n ) / terms ) -terms + 1)/2;
            if( (terms * (2*first + terms - 1)) == 2 * n)
            {
                second = first + terms - 1;
                break;
            }
        }
        printf("%lld = %lld + ... + %lld\n", n, first, second);
    }
    return 0;
}