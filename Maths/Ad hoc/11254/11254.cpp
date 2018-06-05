#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);


    while (1)
    {
        long long int n;
        cin >> n;
        if (n == -1)
        break;
        bool found = false;
        long long int first ,second , terms , sum;
        long long int a , b , c;
        for (int i = 1 ; i <= n ; i++)
        {
            first = i;
            a = 1;
            b = 2 * first - 1;
            c = - 2 * n;
            terms = (- b + sqrt (b*b - 4 * a * c))/ 2*a;
            second = first + terms - 1;
            sum = (terms * (2 * first + terms - 1))/2;
            if (sum == n)
            break;

        }
        printf("%lld = %lld + ... + %lld\n" , n , first , second);
    }
    return 0;
}