#include <bits/stdc++.h>
using namespace std;

vector <long long int> prime;
long long int sieve_size;
bitset <200010> bs;

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
            for (long long int j = i*i ; j<= sieve_size ; j+=i)
            bs[j] = 0;
            prime.push_back(i);
        }
    }
}

vector <long long int> factor;
void primeFactors (long long int N)
{
    long long int PF_idx = 0;
    long long int PF = prime[PF_idx];

    while (PF * PF <= N)
    {
        int freq = 0;
        while ( N % PF == 0)
        {
            N = N/PF;
            freq++;
        }
        PF = prime[++PF_idx];
        if (freq != 0)
        factor.push_back(freq);
    }
    if (N != 1)
    factor.push_back(1);

}



int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    sieve (200000);
    while (1)
    {
        long long int n;
        cin >> n;
        if ( n == 0)
        break;

        factor.clear();
        primeFactors(n);
        long long int ans = 0;
        int len = factor.size();
        for (int i =0 ; i < len ; i++)
        {
            long long int temp = factor[i];
            for (int j = i+1 ; j < len ; j++)
            temp = temp * (2*factor[j] + 1);
            ans += temp;
        }
        ans += 1;
        cout << n << " " << ans << endl;
    }
    return 0;
}