#include <bits/stdc++.h>
using namespace std;

bitset <1010> bs;
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

long long int primeFactor (long long int N)
{
    long long int ans = 1;
    long long int PF_idx = 0;
    long long int PF = prime[PF_idx];
    while (PF * PF <= N)
    {
        int freq = 0;
        while (N % PF == 0)
        {
            freq++;
            N = N/PF;
        }
        if (freq != 0)
        ans *= ((long long )(pow( double (PF) , freq+1.0 )) - 1 )/ (PF-1);
        PF = prime[++PF_idx];
    }
    if (N != 1)
    ans *= ((long long)(pow (double (N) , 2.0)) - 1 )/ (N-1); 
    return ans;
}


int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    sieve (1000);
    long long int factors[1000];
    factors[1] = 1;
    for (int i =2 ; i <= 1000 ; i++)
    factors[i] = primeFactor(i);

  //  for (int i=1 ; i <= 1000 ; i++)
  //  cout << factors[i] << endl;
    int cases = 0;
    while (1)
    {
        cases++;
        long long int n ;
        cin >> n;
        if (n == 0)
        break;

        int ans = -1;
        for (int i = 1000 ; i > 0 ; i--)
        {   
            if (factors[i] == n)
            {
                ans = i;
                break;
            }
        }
        cout << "Case " << cases << ": " << ans << endl;

    }
    return 0;
}