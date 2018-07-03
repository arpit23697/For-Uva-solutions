#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    string str;
    while(cin >> str)
    {
        sort (str.begin() , str.end());
        int index =-1;
        for (int i= 0 ; i < str.size() ; i++)
        {
            if (str[i] != '0')
            {
                index = i;
                break;
            }
        }
     /*   for (int i= 0 ; i < str.size() ; i++)
        cout << str[i] << " " ;
        cout <<endl;
       */ long long int big = 0;
        int power = 0;
        for (int i= str.size() - 1 ; i >=0 ; i--)
            big += (str[i] - '0') * pow (10 , i);         
        
        swap (str[0] , str[index]);
      /*  for (int i= 0 ; i < str.size() ; i++)
        cout << str[i] << " " ;
        cout <<endl;
*/
        long long int small = 0;
        power = str.size() -1;
        for (int i= 0 ; i < str.size() ; i++)
        {
            small += (str[i] - '0') * pow (10 , power);
           // cout << small << endl;
            power--;
        }
        cout << big << " - " << small << " = " << big - small << " = 9 * " << (big-small)/9  << endl;
    }
    return 0;
}