#include <bits/stdc++.h>
using namespace std;
/*
bitset <20000010> bs;
vector <long long int > prime;
long long int sieve_size;

void sieve (long long int upperbound)
{
    sieve_size = upperbound + 1;
    bs.set();
    bs[0] = 0;
    bs[1] = 0;
    for (long long int i = 2; i <= sieve_size ; i++)
    {
        if (bs[i] == 1)
        {
            for (long long int j = i*i ; j <= sieve_size ; j+=i)
            bs[j] = 0;
            prime.push_back(i);
        }
    }
}

long long int power (long long int n ,long long int p)
{
    int ans = 0;
    while (n / p != 0)
    {
        n = n/p;
        ans += n;
    }
    return ans;
}

long long int computePower (long long int x , long long int y)
{
    long long int res = 1;
    x = x%10;
    while (y > 0)
    {
        if (y%2 == 1)
        res = (res * x) % 10;
        y = y / 2;
        x = (x*x) % 10;
    }
    return res;
} 
*/
int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    long long int n , m;
  //  sieve(20000000);
  //  int size = prime.size();
    while (scanf("%lld %lld" , &n , &m) == 2)
    {
        long long ans = 1;
        for (long long int i = n ; i > n-m ; i--)
        {
            ans = ans * i;
            while(ans % 10 == 0) ans = ans/10;
            ans = ans % 1000000000;
        }
        cout <<ans%10 <<endl;

/*
        if (m == 0)
        {
            cout << "1" << endl;
            continue;
        }
        m = n-m;
      //  cout << n << " " << m << endl;
      //  cout << power (n , 2) << " " << power (m , 2) << endl;
      //   cout << power (n , 5) << " " << power (m , 5) << endl;
        long long int c2 = power (n , 2) - power (m , 2);
        long long int c5 = power (n , 5) - power (m , 5);
       // cout << c2 << " " << c5 << endl;
        long long int ans = 1;
        
        if (c2 > c5)
        ans = computePower (2 , c2 - c5);
        else if (c5 > c2)
        ans = computePower (5 , c5 - c2);
        for (long long int i = 0; i < size ; i++)
        {
            if (i == 0 || i == 2)
            continue;

            if (prime[i] > n)
            break;
            long long int temp1 = power (n , prime[i]) - power (m , prime[i]);
            long long int temp2 = computePower (prime[i] , temp1);
            ans = (ans * temp2) % 10;

        }

        cout << ans <<endl;
*/
    }
    return 0;
}