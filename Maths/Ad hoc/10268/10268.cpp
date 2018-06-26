#include <bits/stdc++.h>
using namespace std;

long long int power (long long x , long long y)
{
    if (y < 0 )
    return 0;
    if (y == 0)
    return 1;

    long long ret = 1;
    if (y%2 ==1)
    {
        ret = power (x, y/2);
        return ret * ret * x;
    }
    else 
    {
        ret = power (x , y/2);
        return ret * ret;
    }
}



int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    string str;
    long long int x;
    while (scanf("%lld\n" , &x) == 1)
    {
    //    cout << str << endl; 
      //  cout << "X " << x << endl;   
        getline(cin , str); 
        istringstream s(str);
        vector <long long int> coef;
        long long int temp;
        while (s >> temp)
        coef.push_back(temp);


        long long int n = coef.size();
            
            long long int ans = 0;
            for (long long int j = n-2 ; j >= 0 ;j-- )
           {
            
            ans += coef[j] * (n-1-j)*power (x , n-1 - j-1);
           }
        cout << ans << endl;
    
    }
        
    return 0;
}