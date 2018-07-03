#include <bits/stdc++.h>
using namespace std;

long long int sieve_size;
bitset <40010> bs;
vector <long long int> prime;

void sieve (long long int upperbound)
{
    sieve_size = upperbound + 1;
    bs.set();
    bs[0] =0;
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

vector <pair <long long int , long long int>> factors;
void primeFactor (long long int N)
{
    long long int PF_idx = 0;
    long long int PF = prime[PF_idx];
    while (PF * PF <= N)
    {
        int freq =0;
        while (N % PF == 0)
        {
         //   cout << PF << " ";
            N = N / PF;
            freq++;
        }
        if (freq >= 1)
        factors.push_back(make_pair (PF , freq));
        PF = prime[++PF_idx];
    } 
    //cout << endl;
    if (N != 1)
    factors.push_back(make_pair(N , 1));
}

int main ()
{
    sieve(40000);
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    while (1)
    {
        string str;
        getline (cin , str);
        if (str.length() == 1)
        break;

        istringstream is (str);
        long long int temp , x;
        long long int n = 1;
        while (is >> x)
        {
            is >> temp;
            n = n * pow (x , temp);
        }
       // cout << n << " n " << endl;
        n-=1;
        factors.clear();
        primeFactor(n);
        int len = factors.size();
        cout << factors[len-1].first << " " << factors[len-1].second;
        for (int i = len - 2 ; i >= 0 ; i--)
        cout << " " << factors[i].first << " " << factors[i].second;
        cout << endl;
    }
    return 0;
}