#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    while (1)
    {
        string str;
        cin >> str;
        if (str == "0")
        break;

        long long int ans = 0;
        int size = str.size();
        for (int i = size - 1  ; i >= 0 ; i--)
        {
            int x = str[i] - '0';
            //cout << x << endl;
            ans += x * (pow(2 , size- i)  - 1);
           // cout << x << " " <<  (pow (2 , i+1) - 1) << endl ;
        }
        cout << ans << endl;
    }
    return 0;
}