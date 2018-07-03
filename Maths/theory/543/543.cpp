#include <bits/stdc++.h>
using namespace std;

long long int sieve_size;
vector <long long int> prime;
bitset <1000010> bs;

void sieve (long long int upperbound)
{
    sieve_size = upperbound + 1;
    bs.set();
    bs[0] = 0;
    bs[1] = 0;
    for (long long int i = 2 ; i <= sieve_size ; i++)
    {
        if (bs[i])
        {
            for (long long int j = i*i ; j <= sieve_size ; j+=i)
            bs[j] = 0;
            prime.push_back(i);
        }
    }
}



int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);

    sieve(1000000);
    int len = prime.size();
    while (1)
    {
        long long int n;
        cin >> n;
        if (n == 0)
        break;

        long long int x , y;
        bool ans = false;
        for (int i = 0 ; i < len ; i++)
        {
            if ( bs[n - prime[i]] == 1)
            {
                x = prime[i];
                y = n - prime[i];
                ans = true;
                break;
            }
        }
        if (ans)
        cout << n << " = " << x << " + " << y << endl;
        
        else
        cout << "Goldbach's conjecture is wrong." << endl;
        
    }
    
    
    return 0;
}