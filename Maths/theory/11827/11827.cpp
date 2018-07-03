#include <bits/stdc++.h>
using namespace std;

int gcd (int a , int b)
{
    if (b == 0)
    return a;
    
    return gcd (b ,a%b);
}

int main ()
{
    freopen ("in.txt" , "r" ,stdin);
    freopen ("out.txt" , "w" , stdout);

    int test;
    cin >> test;
    cin.ignore(100 , '\n');
    while(test--)
    {
        string str;
        getline(cin , str);
        istringstream is(str);
        int temp;
        vector <int> num;
        while(is >> temp)
        num.push_back(temp);

        int ans = gcd (num[0] , num[1]);
        int len = num.size();
        for (int i =0 ; i < len ; i++)
        {
            for (int j = i+1 ; j < len ; j++)
            {
                temp = gcd (num[i] , num[j]);
                ans = max (ans , temp);
            }
        }
        cout << ans <<endl;
    }

    return 0;
}