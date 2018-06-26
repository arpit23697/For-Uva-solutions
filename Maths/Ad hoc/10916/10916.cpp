#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    while (1)
    {
        int year;
        cin >> year;
        if (year == 0)
        break;

    
        long long int n = pow (2 , (year - 1940)/10);
    //    cout << n << endl;
        double temp = 0;
        int ans = 1;
        while (n > temp)
        {
          //  cout << temp << " " << ans << " " << n << endl;
            ans++;
            temp += log2 (ans);
            
           
        }
        cout << ans-1 << endl;
    
    }


    return 0;
}