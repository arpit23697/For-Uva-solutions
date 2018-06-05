#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    long long int r , n;
    int cases = 0;
    while (1)
    {
        cases++;
        cin >> r >> n;
        if (r == 0 && n ==0)
        break;

        int ans = 0;
        if (r%n == 0)
        ans = r/n - 1;
        else
        ans = r/n;
        cout << "Case " << cases << ": ";
        if (ans > 26)
        cout << "impossible" << endl;
        else
        cout << ans<<endl;
    }
    return 0;
}