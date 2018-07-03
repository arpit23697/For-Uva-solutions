#include <bits/stdc++.h>
using namespace std;

bitset <10000010> bs;
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

vector <long long int > factors;
int primeFactor (long long int N)
{
    int ans = 0;
    long long int PF_idx = 0;
    long long int PF = prime[PF_idx];
    while (PF * PF <= N)
    {
        int freq = 0;
        while (N % PF == 0)
        {
            freq++;
            N = N/PF;
            factors.push_back (PF);
        }
        if (freq != 0)
        ans++;
        PF = prime[++PF_idx];
    }
    if (N != 1)
    {
    ans++;
    factors.push_back(N);
    }
    return ans;
}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    sieve (10000000);
    while (1)
    {
        long long int n;
        cin >> n;
        if (n == 0)
        break;
        factors.clear();
        int ans = primeFactor(abs(n));
        if (ans <= 1)
        cout << "-1" << endl;
        
        else
            cout << factors[factors.size()  - 1] << endl;
        
        
    }
    return 0;
}