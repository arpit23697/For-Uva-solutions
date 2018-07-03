#include <bits/stdc++.h>
using namespace std;

bitset <100010> bs;
long long int sieve_size;
vector <long long int > prime;

void sieve(long long int upperbound)
{
    sieve_size = upperbound + 1;
    bs.set();
    bs[0] = 0;
    bs[1] = 1;
    for (long long int i =2 ; i <= sieve_size ; i++)
    {
        if (bs[i] == 1)
        {
            for (long long int j= i*i ; j<= sieve_size ; j+=i )
            bs[j] = 0;
            prime.push_back(i);
        }
    }
}

int primeFactor (long long int N)
{
    long long int PF_idx = 0;
    long long int PF = prime[PF_idx];
    int ans = 1;
    while (PF * PF <= N)
    {
        int freq = 0;
        while (N % PF == 0)
        {
            N = N / PF;
            freq++;
        }
        ans *= freq + 1;
        PF = prime[++PF_idx];
    }
    if ( N != 1)
    ans *= 2;
    return ans;
}


int main ()
{
    freopen ("in.txt", "r" ,stdin);
    freopen ("out.txt", "w" , stdout);
    sieve (100000);
    while (1)
    {
        long long int n;
        cin >> n;
        if (n == 0)
        break;
        int ans = primeFactor (n);
        if (ans % 2 == 0)
        cout << "no" << endl;
        
        else
        cout << "yes" <<endl;
         
    }
   
    return 0;
}