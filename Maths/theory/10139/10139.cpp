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


//this is important as it tells how to find the exponent of a prime p in n!
vector <pair <long long int, long long int> > factors;
void primeFactor (long long int N)
{
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
        factors.push_back(make_pair(PF , freq));
        PF = prime[++PF_idx];
    }
    if (N != 1)
    factors.push_back(make_pair(N, 1));
    
}

//this finds the exponent of a prime p in n!
int power (int n , int p)
{
    int ans = 0;
    while (n!=0)
    {
        ans += n/p;
        n = n/p;
    }
    return ans;
}
int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    sieve (10000000);
    long long int m , n;
    while (scanf("%lld %lld", &n , &m) == 2)
    {


        factors.clear();
        primeFactor(m);
        bool ans = true;
        int len = factors.size();

        if (m == 0)
        ans = true;
        else
        for (int i =0 ; i < len ; i++)
        {
            int x = factors[i].first;
            int freq = factors[i].second;
            if (freq > power (n ,  x))
            {
                ans = false;
                break;
            }
        }
        if (ans )
        cout << m <<" divides "<< n <<"!" << endl;
        
        else
        cout << m <<" does not divide "<< n <<"!" << endl;
        
    }
    return 0;
}