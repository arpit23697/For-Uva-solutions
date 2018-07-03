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
        long long int n;
        cin >> n;
        if (n == 0)
        break;

        
        cout << "Case " << cases << ": ";
        
        long long int a = 1;
        long long int b = -3;
        long long int c =  -2*n;
        long long int ans = ceil((-b + sqrt(b*b - 4*a*c))/(1.0 * 2*a));
        cout << ans <<endl;
      //  cout << ceil(ans) << endl;
    }
    return 0;
}