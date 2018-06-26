#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
        break;

        cout << floor (log2(n)) << endl;
    }
        
    return 0;
}