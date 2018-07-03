#include <bits/stdc++.h>
using namespace std;

long long int x , y , d;
void Euclid (long long int a , long long int b)
{
    if (b == 0) 
    {
        x = 1;
        y = 0;
        d = a;
        return ;
    }
    Euclid (b , a%b);
    long long int x1 = y;
    long long int y1 = x - (a/b) * y;
    x = x1;
    y = y1;
}

int main ()
{
    freopen ("in.txt", "r" ,stdin);
    freopen ("out.txt", "w" , stdout);
    
    int test;
    cin >> test;
    while(test--)
    {
        long long int  n, k;
        cin >> n >> k;
        long long int a = floor(1.0 * n / k);
        long long int b = ceil (1.0 * n / k);
        Euclid (a , b);
        x = x * ( n / d);
        y = y * (n / d);
        cout << x << " " << y << endl;
    }
    return 0;
}