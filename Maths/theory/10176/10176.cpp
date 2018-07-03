#include <bits/stdc++.h>
using namespace std;


int E = 131071;
long long int power (long long int x ,long long int y)
{
    long long int res = 1;
    x = x%E;
    while (y > 0)
    {
        if (y % 2 == 1)
        res = (res * x) % E;
        y = y/2;
        x = (x*x) % E;
    }
    return res;
}



int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" ,"w" , stdout);
    string str;
    while (cin >> str)
    {
        string num = str;
        while (num[num.size() - 1] != '#')
        {
            cin >> str;
            num = num + str;
        }
        int len = num.size();
        int ans = 0;
        int powr = 0;
        for (int i = len - 2 ; i >= 0 ; i--)
        {
            //cout << power (2 , powr) << endl;
            if (num[i] == '1')
            {
                long long int temp = power (2 , powr);
                ans =( ans + temp ) % E;
            }
            powr++;
        }

        if (ans == 0)
        cout << "YES" << endl;
        
        else
        cout << "NO" << endl;
        
    }
    return 0;
}