#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    int cases= 0;
    while(1)
    {
        cases++;
        int n;
        cin >> n;
        if (n == 0)
        break;

        
        cout << "Case " << cases << ": ";
        if (n==1)
        cout << "0" << endl;
        else
        cout << ((n * (n-1))/2 )/(n-1) << endl;
    }
    return 0;
}