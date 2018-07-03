#include <bits/stdc++.h>
using namespace std;

int gcd (int a , int b)
{
    if (b == 0)
    return a;
    else
    return gcd (b , a%b);
}


int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    while(1)
    {
        vector <long long int> num;
        long long int temp;
        cin >> temp;
        if (temp == 0)
        break;


        long long int a , b;
        while(1)
        {
            a = temp;
            cin >> temp;
            b = temp;
            if (temp == 0)
            break;
         //   cout << b-a << " ";
            if (a != b)
            num.push_back(b-a);
        
        }
       // cout << endl;
       // cout << gcd (-9 , -6) << " hiii" << endl;
        int len = num.size();
        long long int ans = abs(num[0]);
        for (int i = 1 ; i < len ; i++ )
        ans = gcd (ans , abs(num[i]));
        cout << ans << endl;
    }
    return 0;
}