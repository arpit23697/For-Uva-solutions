#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen("in.txt" , "r"  , stdin);
    freopen("out.txt" , "w" , stdout);
    long long int n;
    while (scanf ("%lld" , &n) == 1)
    {
        long long int level = 0;
        long long int temp = 1;
        long long int x=0 , y=0;
        while (n > temp)
        {
            temp += level * 6;
            level += 1;
        }
        if (n == 1){
            cout << "0 0" << endl;
            conntinue;
        }
        if (n == temp)
        {
            cout << level-1 << " " << y << endl;
            continue;
        }
        level-=1;
        temp -= level * 6;
     //   cout << "level "  << level << "temp  " << temp << endl;
        x = level;
        y = 0;
        
        long long int level2 = level ;
        while (level2-- && temp < n)
        {
            x -= 1;
            y++;
            temp+=1;
        }
        level2 = level;
        while (level2-- && temp < n)
        {
            x--;
            temp+=1;
        }
        level2 = level;
        while (level2-- && temp < n)
        {
            y--;
            temp+=1;
        }
        level2 = level;
        while (level2-- && temp < n)
        {
            x+=1;
            y--;
            temp+=1;
        }
        level2 = level;
        while (level2-- && temp < n)
        {
            x++;
            temp++;
        }
        while (level2-- && temp < n)
        {
            y++;
            temp++;
        }
        cout << x << " " << y << endl;


        

    }

    return 0;
}