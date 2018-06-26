#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    while (1)
    {
        long long int n , k;
        cin >> n >> k;
        if (n == -1 && k == -1)
        break;

        vector <long long int> coef(n+1);
        for (int i= 0 ; i <= n ; i++)
        cin >> coef[i];

        if (n < k)
        {
            cout << coef[0];
            for (int i =1 ;  i<= n ; i++)
            cout << " " << coef[i];
            cout << endl;
        }
        
        else
        {
            long long int rem = n - k;
            long long int temp;
            while (rem >= 0)
            {
                temp = coef[rem+k];
                coef[rem] -= temp;
                coef[rem+k] = 0;
                rem--;
            }
            cout << coef[0];
            for (int i= 1 ; i < k ; i++)
            cout << " " << coef[i];
            cout << endl;
        }
        

    }
        
    return 0;
}