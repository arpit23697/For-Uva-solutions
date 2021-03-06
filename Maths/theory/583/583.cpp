#include <bits/stdc++.h>
using namespace std;

bitset <100010> bs;
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
void primeFactor (long long int N)
{
    long long int PF_idx = 0;
    long long int PF = prime[PF_idx];
    while (PF * PF <= N)
    {
        while (N % PF == 0)
        {
            N = N/PF;
            factors.push_back (PF);
        }
        PF = prime[++PF_idx];
    }
    if (N != 1)
    factors.push_back(N);
}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    sieve (100000);
    while (1)
    {
        long long int n;
        cin >> n;
        if (n == 0)
        break;
        factors.clear();
        primeFactor(abs(n));
        cout << n << " =";
        bool first = false;
        int start = 0;
        if (n < 0)
        {
            start = 0;
            cout << " -1";
            first = true;
        }
        int len = factors.size();
        if (!first)
        {
            cout << " " << factors[0];
            first = true;
            start = 1;
        }
        for (int i =start ; i < len ; i++)
        cout << " x " << factors[i] ;
        cout << endl;
    }
    return 0;
}