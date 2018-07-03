#include <bits/stdc++.h>
using namespace std;

bitset <20000010> bs;
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
        }
    }
}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    sieve(20000000);
    vector <pair <int ,int >> ans;
    for (int i= 2; i <= 20000000 - 2 ; i++ )
    {
        if (bs[i] && bs[i+2])
        ans.push_back(make_pair(i , i+2));
    }
   // cout << ans.size() << endl;
    int n;
    while (scanf("%d",&n) == 1)
    {
        cout << "(" <<ans[n-1].first << ", " << ans[n-1].second << ")" << endl;
    }

    return 0;
}