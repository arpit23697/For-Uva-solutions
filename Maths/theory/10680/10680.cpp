#include <bits/stdc++.h>
using namespace std;

bitset <1000010> bs;
long long int sieve_size;
vector <long long int> prime;

void sieve (long long int upperbound)
{
    sieve_size = upperbound + 1;
    bs.set();
    bs[0] =  0;
    bs[1] = 0;
    for (long long int i = 2; i <= sieve_size ; i++)
    {
        if (bs[i] == 1)
        {
            for (long long int j = i*i ; j <= sieve_size ; j+=i)
            bs[j] = 0;
            prime.push_back (i);
        }
    }
} 

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    sieve (1000000);
    long long int  n;
    int size = prime.size();
 //   cout << size << endl;
    while (1)
    {
        cin >> n;
        if (n == 0)
        break;

       
       int c2 =floor ( (log(n) * 1.0) / log(2));
       int c5 = floor ( (log(n) * 1.0) / log(5));
        long long int ans = 1;
        for (int i =0 ; i < c2 - c5; i++)
        ans = ( ans * 2 ) % 10;
        
        for (int i = 0 ; i < size ; i++)
        {
            if (prime[i] > n)
            break;
            if (i != 0 && i != 2)
            {
                long long int temp = pow (prime[i] , floor ( (log(n) * 1.0) / log(prime[i])) );
                ans = (ans *temp)%10 ;
            }
        }
        cout << ans << endl;
        
    }
    return 0;
}