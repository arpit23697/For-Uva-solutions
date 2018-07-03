#include<bits/stdc++.h>
using namespace std;

long long sieve_size;
bitset <10000010> bs;
vector <long long int> primes;


void sieve (long long upperbound)
{
    sieve_size = upperbound + 1;                //add 1 to include the upperbound
    bs.set();                                   // set all bits to 1    // 1 means prime and 0 means prime 
    bs[0] = 0;                                  // except 0 and 1 , bs
    bs[1] = 0;
    for (long long i = 2 ; i <= sieve_size ; i++)
    {
        if (bs[i] == 1)
        {
            for (long long j = i*i ; j<= sieve_size ; j+=i)
                bs[j] = 0;
            primes.push_back(i);
        }
    }
}

bool isPrime (long long int x)
{
    if (x <= sieve_size)return bs[x];
    for (int i = 0 ; i < primes.size() ; i++)
    if (x % primes[i] == 0)return false;
    return true;
}

int gcd (int a , int b) {
    if ( b == 0)
    return a;
    
    else
        return gcd (b , a%b);
}
int lcm (int a , int b)
{
    return a * (b / gcd (a, b));
}

//note gcd (a , b, c ) = gcd (a , gcd (b , c))
//similarly for lcm
//this function is going to generate the prime factors.
vector <long long int> primeFactors (long long int N)
{
    vector <long long int> factors;
    long long int PF_idx = 0;
    long long int PF = primes[PF_idx];

    while (PF * PF <= N)
    {
 //       cout << PF << endl;
        while (N % PF == 0){
            N /= PF;
            factors.push_back(PF);
        }
        PF_idx++;
        PF = primes[PF_idx];
    }
    if (N != 1)factors.push_back(N);
    return factors;
}

int main ()
{
    sieve(10000000);
    cout << isPrime(31) << endl;
    cout << isPrime(2147483647) << endl;
    cout << isPrime(2147483647) << endl;
    
    vector <long long int> ans = primeFactors(136117223861);
    for (int i= 0 ; i < ans.size() ; i++)
    cout << ans[i] << " ";
    cout << endl;
    
    return 0;  


}