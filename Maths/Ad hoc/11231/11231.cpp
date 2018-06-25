#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);

    while (1)
    {
        long long int n , m , black;
        cin >> n >> m >> black;
        if (n == 0 && m == 0 && black == 0)
        break;

        long long int ans = (n-7)*(m-7);
        if (ans % 2 == 0)
        cout << ans/2 <<endl;

        else 
        {
            if (black == 1)
            cout << ans / 2 + 1 << endl;
            else 
            cout << ans/2 <<endl;
        }
    }
    return 0;
}