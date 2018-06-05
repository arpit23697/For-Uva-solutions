#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int test;
    cin >> test;
    while (test--)
    {
        long long int n; 
        double ans;
        cin >> n;
        if (n == 1)
        ans = 0;
        else
        {
            long long int sum = 0;
            if (n-2 > 0)
            sum = n-2;
            for (int i= 1 ; i <= n-3 ; i++)
            sum += 2 * i;
            ans = n*n + sum * (sqrt (2) - 1);

        }
        printf ("%.3lf\n" , ans);
        if (test > 0)
        cout << endl;
    }
    return 0;
}