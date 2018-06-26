#include <bits/stdc++.h>
using namespace std;

long long int power (long long int x , long long int y , long long int mod)
{
    long long int res= 1;
    x = x % mod;

    while (y > 0)
    {
        if (y % 2 != 0)
        res = (res * x)%mod;

        y = y/2;
        x = (x*x)%mod;
    }
    return res;
}



int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    int test ;
    cin >> test;
    int cases =0 ;
    while (test--)
    {
        cases++;
        long long int n , k , mod;
        cin >> n >> k >> mod;
        if (n == -1 && k == -1)
        break;

        long long int sum = 0;
        long long int x = 0; 
        for (int i= 0 ; i < n ; i++)
        {
            cin >> x;
            sum += x;
        }
        long long int ans ;
        ans = power (n , k-1 , mod);

        ans = ((ans % mod)* ( k % mod )) % mod;
        ans = ((ans % mod)* ( sum % mod )) % mod;
        cout << "Case " << cases << ": "<<ans << endl;
    }
        
    return 0;
}