#include <bits/stdc++.h>
using namespace std;

vector <long long int > factors;
long long int n;

bool findFactors(long long int x)
{
 //   cout << x << " x" <<endl; 
    double x_temp = x;
    bool flag = false ;
  //  cout << x_temp << " " << sqrt(x) << endl;
    for (long long int i = 2 ; i <=sqrt(x_temp)  ; i++)
    {
            //cout << "x_temp " << x  << " i  " << i << endl;
            while (x % i == 0)
            {
              //  cout << i << endl;
                factors.push_back(i);
                x = x/i;
                flag = true;
            }
        
    }
    if (x!= 1)
    factors.push_back(x);
    return flag;
}

long long int digits (long long int x)
{
    long long int ans = 0;
    while (1)
    {
        ans += x%10;
        x =  x/10;
        if (x == 0)
        return ans;
    }
}
int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);

    int test;
    cin >> test;
    while (test--)
    {
        
        cin >> n;
        long long int smith = -1;
        for (long long int i= n+1 ; ; i++)
        {
            factors.clear();
            bool temp = findFactors(i);
            long long int sum = 0;
            for (int i= 0 ; i < factors.size() ; i++)
                sum += digits(factors[i]);
            
            if (sum == digits(i) && temp)
            {
                smith = i;
                break;
            }
        }
        cout << smith << endl;
    }


    return 0;
}