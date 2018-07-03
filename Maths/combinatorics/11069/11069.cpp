#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);

    long long int ans[90];
    ans[0] = 1;
    ans[1] = 0;
    ans[2] = 0; 
    for (int i= 3; i <= 90 ; i++)
    ans[i] =  ans[i-2] + ans[i-3];
  
    long long int n;
    while(scanf("%lld",&n) == 1)
    {
        cout << ans[n+6] << endl;
    }
    return 0;
}