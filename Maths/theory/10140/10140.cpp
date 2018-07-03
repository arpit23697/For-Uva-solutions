#include <bits/stdc++.h>
using namespace std;

vector <long long int> prime;
bitset <1000010> bs;
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

bool isPrime (long long int N)
{
    if ( N <= sieve_size) return bs[N];
    for (int i = 0; i < prime.size() ; i++)
    {
        if (N % prime[i] == 0) return false;
        if (prime[i] > sqrt(N))
        break;
    }
    return true;
}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    sieve(1000000);

    long long int L , U;
    while (scanf ("%lld %lld", &L , &U) == 2)
    {
       // cout << L << " " << U << endl;
        long long int x1 , y1 , x2 , y2;

        int first = 0;
        long long int mini , maxi;
        long long int a , b;
        for (long long int i = L; i <= U ; i+=1)
        {
          //  cout << i << endl;
            if (isPrime(i) == true)
            {
            //    cout << i << endl;
                first++;
                if (first == 1)
                {
                    a = i;
                    x1 = i;
                    x2 = i;
                }
                else if (first == 2)
                {
                    b = i;
                    y1 = i;
                    y2 = i;
                    mini = b - a;
                    maxi = b - a;
                }
                else if (first > 2)
                {
                    
                    a = b;
                    b = i;
                 //   cout << a << " " << b << endl;
                    if (b - a > maxi)
                    {
                        x1 = a;
                        y1 = b;
                        maxi = b-a;
                    }
                    if (b - a < mini)
                    {
                        x2 = a;
                        y2 = b;
                        mini = b-a;
                    }
                }
            }
            
        }

        if (first < 2)
        cout << "There are no adjacent primes." << endl;
        else
        printf("%lld,%lld are closest, %lld,%lld are most distant.\n" , x2 , y2 , x1 , y1);
    }
    
    return 0;

}