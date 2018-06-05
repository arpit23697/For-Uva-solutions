#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
   cout << "PERFECTION OUTPUT" << endl;
    while (1)
    {
        long long int n;
        cin >> n;
        if (n == 0)
        break;
        int ans =0 ;
        for (int i= 1 ; i <= n/2 ; i++)
        {
            if (n%i == 0)
            ans += i;
        }

        printf("%5lld  ", n);
        if (ans == n)
        cout << "PERFECT" << endl;
        else if (ans < n)
        cout << "DEFICIENT" << endl;
        else
        cout << "ABUNDANT" << endl;

        
    }
    cout << "END OF OUTPUT" << endl;
     return 0;
}