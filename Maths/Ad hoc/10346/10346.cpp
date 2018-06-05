#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    long long int n , k;
    while (scanf ("%lld %lld", &n , &k) == 2)
    {
        long long int ans = 0;
        int current = n;
        int remaining = 0;
        while (current != 0)
        {
           
            ans+= current;
            remaining += current;
            current = remaining / k;
           // cout << current << " " << remaining << endl;
            remaining = remaining % k;
        }
        
        
        cout << ans << endl;
    }

    return 0;
}