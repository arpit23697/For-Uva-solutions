#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    while (1)
    {
        long long int n;
        cin >> n;
        if (n == 0)
        break;

        int temp2 = 0;
        bitset <32> ans (n);
        //cout << ans << endl;
        for (int i = 31 ; i >= 0; i--)
        if (ans[i] == 1)
        {
            temp2 = i;
            break;
        }
      //  cout << temp2 << endl;
        int temp = ans.count();
        printf("The parity of ");
        for (int i= temp2 ; i >= 0 ; i--)
        if (ans[i] == 1)
        cout << "1";
        else
        cout << "0";

        printf(" is %d (mod 2).\n",temp);
    }
    
    return 0;
}