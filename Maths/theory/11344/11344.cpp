#include <bits/stdc++.h>
using namespace std;
string num;

bool divisible_2 ()
{
    if ( (num[0] - '0') % 2 ==0 )
    return true;
    return false;
}
bool divisible_3 ()
{
    int sum = 0;
    for (int i=0; i < num.size() ; i++)
    sum += num[i] - '0';
    if (sum % 3 == 0)
    return true;
    return false;
}
bool divisible_4 ()
{
    if (num.size() == 1 && (num[0] == '4' || num[0] == '8' || num[0] == '0'))
    return true;
    if (num.size() > 1)
    {
        int temp = 10 * (num[1] - '0');
        temp += num[0] - '0';
        if (temp % 4 == 0)
        return true;
    }
    return false;
}
bool divisible_5 ()
{
    if (num[0] == '5' || num[0] == '0')
    return true;
    return false;
}
bool divisible_6 ()
{
    if (divisible_2() && divisible_3() )
    return true;
    return false;
}
bool divisible_7 ()
{
    int r[6];
    for (int i = 0 ; i < 6 ;i++)
    r[i] = 0;
    for (int i =0 ; i < num.size() ; i++)
        r[i%6] += num[i] - '0';
    
    for (int i= 0 ; i < 6 ; i++)
    r[i] = r[i] % 7;
    int ans = 0;
    for (int i= 0 ; i < 6 ; i++)
    ans = ans + pow (3 , i ) * r[i];
    if (ans % 7 == 0)
    return true;
    return false;
}
bool divisible_8 ()
{
    int ans = num[0] - '0';
    if (num.size() > 1)
    ans += 10 * (num[1] - '0');
    if (num.size() > 2)
    ans += 100 * (num[2] - '0');
    if (ans % 8 == 0)
    return true;
    return false;
}

bool divisible_9 ()
{
    int sum = 0;
    for (int i=0 ; i < num.size() ; i++)
    sum += num[i] - '0';
    if (sum % 9 == 0)
    return true;
    return false;
}
bool divisible_10()
{
    if (num[0] == '0')
    return true;
    return false;
}
bool divisible_11 ()
{
    int r[2];
    r[0] = 0;
    r[1] = 0;
    for (int i=0 ; i < num.size() ; i++)
    r[i%2] += num[i] - '0';
    if ( (r[1] - r[0]) % 11 == 0 )
    return true;
    return false; 
}
bool divisible_12()
{
    if (divisible_3() && divisible_4())
    return true;
    return false;
}


int main ()
{
    freopen ("in.txt", "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    int test;
    cin >> test;
    while (test--)
    {
        string str;
        cin >> str;
        num = "";
        for (int i= 0 ; i < str.size() ; i++)
        num = str[i] + num;
        int n;

        cin >> n ;
        bool realAns = true;
        for (int i= 0; i < n ; i++)
        {
            int x;
            cin >> x;
            bool ans = true;
          if (x == 2)
            ans = divisible_2();
            else if (x == 3)
            ans = divisible_3();
            else if (x == 4)
            ans = divisible_4();
            else if (x == 5)
            ans = divisible_5();
            else if (x == 6)
            ans = divisible_6();
            else if (x == 7)
            ans = divisible_7();
            else if (x == 8)
            ans = divisible_8();
            else if (x == 9)
            ans = divisible_9();
            else if (x == 10)
            ans = divisible_10();
            else if (x == 11)
            ans = divisible_11();
            else if (x == 12)
            ans = divisible_12();
            //cout << x << " " << ans << endl;  
            realAns = ans & realAns;
        }   
        if (realAns)
        cout << str << " - Wonderful." << endl;
        else
        cout << str << " - Simple." << endl; 
    }
    return 0;
}