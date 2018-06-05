#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int test;
    cin >> test;
    int cases = 0;
    while (test--)
    {
        long long int n;
        cases++;
        cin >> n;
        long long int ans = n/2;

       cout << "Case " << cases << ": ";
       for (int i =0 ; i < n ; i++)
       {
           long long int x;
           cin >> x;

           if (ans == i)
           cout << x << endl;
       } 

       
    }
    return 0;
}