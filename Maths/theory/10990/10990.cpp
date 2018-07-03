#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> bs;
int sieve_size;
vector <int> prime;
vector <int> phi;
vector <int> steps;



void sieve (long long int upperbound)
{
    sieve_size = upperbound + 1;
    bs.assign(sieve_size+5 , vector <int>()) ;
    phi.assign (sieve_size+5 , 0);
    steps.assign (sieve_size+5 , 0);

    steps[1] = 0;
    phi[1] = 0;
    cout << endl;
    for (long long int i = 2; i <= sieve_size ; i++)
    {
        if (bs[i].size() == 0)
        {
            for (long long int j = 2*i ; j <= sieve_size ; j+=i)
            bs[j].push_back(i);
            phi[i] = i-1;
            prime.push_back (i);
        }
        
        else
        {
            int temp = i;
            for (int x = 0 ; x < bs[i].size() ; x++)
            {
                temp *= (bs[i][x] - 1);
                temp = temp / bs[i][x];
            }
            if (phi[i] < 0)
            cout << "hi there" <<endl;
            phi[i] = temp;       
        } 
        cout << phi[i];
        if (phi[i] > 0)
        steps[i] = steps[phi[i]] + 1;
        cout <<  " " <<steps[i] << endl;
    }
} 


int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    sieve (2000000);

    int test;
    cin >> test;
    while (test--)
    {

        int n,m ;
        cin >> n >> m;
        int ans = 0;
        for (int i= n ; i<= m ; i++)
        ans += steps[i];

        cout << ans << endl;
    }
    return 0;
}