#include <bits/stdc++.h>
using namespace std;

long long int a , b , n;

long long int func (long long int x)
{
    long long int res = 0;
    res = (x*x) %n;
    res = (res * a ) % n;
    res = (res + b) % n;
    return res; 
}



int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" ,stdout);
    while (1)
    {
        cin >> n;
        if (n == 0)
        break;
        cin >> a >> b;

        long long int tort = func(0);
        long long int hare = func(func(0));
        while (tort != hare)
        {
            tort = func (tort);
            hare = func (func (hare));
        }
        hare = 0;
        long long int mu = 0;
        while (tort != hare)
        {
            tort = func (tort);
            hare = func (hare);
            mu++;
        }
        long long int len = 1;
        hare = func (tort);
        while (tort != hare)
        {
            len++;
            hare = func (hare);

        }
        cout << n - len << endl;
    }   
    return 0;
}