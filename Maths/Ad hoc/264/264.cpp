#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    long long int n;
    while (scanf ("%lld" , &n) == 1)
    {
        long long int a , b, c , terms;
        a = 1;
        b = 1;
        c = -2*n;
        
        long long int ans1 , ans2;
        terms = floor ((-b + sqrt (b * b - 4 * a * c)) / (2 * a));
       // cout << terms << endl;
        

            long long int temp = (terms*terms + terms ) / 2;
           // cout << temp << " temp" << endl;
            if (temp == n)
            {
                if (terms%2 == 0)
                {
                    ans1 = terms;
                    ans2= 1;
                }
                else
                {
                    ans2 = terms;
                    ans1 = 1;
                }
            }
            else
              {  
                if (terms%2 == 0)
                {
                ans1 = terms + 1;
                ans2 = 1;
             //   cout << "==============" << endl;
                for (int i = temp+1 ; i < n ; i++)
                {
                    
                    ans1--;
                    ans2++;
               //     cout << ans1 << " " << ans2 << endl;
                }
                }
                else
                {
                    ans1 = 1;
                    ans2 = terms + 1;
                    for (int i = temp + 1; i < n; i++)
                    {
                        ans2--;
                        ans1++;
                    }
                }
    }
        
        printf("TERM %lld IS %lld/%lld\n" , n , ans1 , ans2);
    }
        return 0;
}