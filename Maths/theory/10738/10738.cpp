#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> bs;
int sieve_size;
vector <int> prime;

vector <int> mu;
vector <int> M;


void sieve (long long int upperbound)
{
    sieve_size = upperbound + 1;
    bs.assign(sieve_size+5 , vector <int>()) ;
    mu.assign (sieve_size+5 , 0);
    M.assign(sieve_size+5 , 0);

    mu[1] = 1;
    M[1] = 1;
 // cout << endl;
    for (long long int i = 2; i <= sieve_size ; i++)
    {
       // cout << bs[i].size() << endl;
        if (bs[i].size() == 0)
        {
            mu[i] = -1;
            M[i] = M[i-1] + mu[i];
            for (long long int j = 2*i ; j <= sieve_size ; j+=i)
            bs[j].push_back(i);
            prime.push_back (i);
        }
        
        else
        {
            int temp = 1;
            for (int x = 0 ; x < bs[i].size() ; x++)
            temp = temp * bs[i][x];
        //    cout << " temp " << temp << endl;
            if (temp != i)
            mu[i] = 0;
            else if (bs[i].size() % 2 == 0)
            mu[i] = 1;
            else 
            mu[i] = -1;
            M[i] = M[i-1] + mu[i];
        }
     //   cout << mu[i] << " " << M[i] << endl;
        
    }
} 


int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    sieve (1000000);

    while (1)
    {

        int n ;
        cin >> n;
        if (n == 0)
        break;
        printf("%8d %7d %7d\n",n , mu[n] , M[n]);
    }
    return 0;
}