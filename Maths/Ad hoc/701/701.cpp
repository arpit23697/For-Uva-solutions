#include <bits/stdc++.h>
using namespace std;


int numOfDigits (long long int x)
{
    int ans = 0;
    while (1)
    {
        if (x == 0)
        break;
        ans++;
        x = x/10;
    }
    return ans;
}

int main ()
{
    freopen ("in.txt" , "r" ,  stdin);
    freopen ("out.txt" , "w" , stdout);
    long long int n;
    while (scanf("%lld" , &n) == 1)
    {
        
        int digits = numOfDigits(n) + 1;
      //  cout << digits << endl;
        double small , large;
        int ans = 0;
        while (1)
        {
        
            small = log2(n) + digits*log2(10);
            large = log2(n+1) + digits*log2(10);
          //  cout << small << " " << large << endl;
            if (int(small) < int(large)) 
            {
                ans = ceil(small);
                break;
            }
            digits++;

        }
        cout << ans << endl;
    }
    return 0;
}
