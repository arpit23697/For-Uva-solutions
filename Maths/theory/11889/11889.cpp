#include <bits/stdc++.h>
using namespace std;

bitset <10010> bs;
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
int size;
vector <pair <long long int , long long int >> factors1;

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
        factors1.push_back(make_pair(PF , freq));
        PF = prime[++PF_idx];
    }
    if (N != 1)
    factors1.push_back(make_pair(N , 1));

}
vector <pair <long long int , long long int >> factors2;
void primeFactor2 (long long int N)
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
        factors2.push_back(make_pair(PF , freq));
        PF = prime[++PF_idx];
    }
    if (N != 1)
    factors2.push_back(make_pair(N , 1));

}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    sieve (10000);
    long long int  n;
     size = prime.size();
    int test;
    cin >> test;

    while (test--)
    {
        long long int a , c;
        cin >> a >> c;
        factors1.clear();
        factors2.clear();
        primeFactor(c);
        primeFactor2(a);

        bool ans = true;
        long long int realAns = 1;

       // for (int i= 0 ; i < factors2.size() ; i++)
     //   cout << factors2[i].first << " " << factors2[i].second << endl;

        for (int i = 0 ; i < factors1.size() ; i++)
        {
            int x = factors1[i].second;
            int y = 0;
            for (int j = 0 ; j < factors2.size() ; j++)
            {
                if (factors1[i].first == factors2[j].first)
                {
                    y = factors2[j].second;
                    factors2[j].second = 0;
                    break;
                }
            }
            if (y > x)
            { 
                ans = false;
                break;
            }
            else if (x > y)
            realAns = realAns * pow(factors1[i].first , x);

        }
       
        for (int i = 0 ; i < factors2.size() ; i++)
        if (factors2[i].second > 0)
        {
            ans = false;
            break;
        }
        if (!ans)
        cout << "NO SOLUTION" << endl;
        else
        cout << realAns << endl;
        
    }
    return 0;
}