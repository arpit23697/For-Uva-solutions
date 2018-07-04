#include <bits/stdc++.h>
using namespace std;

long long int Z , I , M;

long long int func (long long int L)
{
    return (Z * L + I ) % M;
}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    int cases = 0;
    while (1)
    {
        cases++;
        long long int L;
        cin >> Z >> I >> M >> L;
        if (Z == 0 && I == 0 && M == 0 && L == 0)
        break;
        long long int tort , hare;
        tort = func(L);
        hare = func(func(L));
        while (tort != hare)
        {
            tort = func (tort);
            hare = func (func(hare));
        }
        long long int mu =0;
        hare = L;
        while (tort != hare)
        {
            tort = func(tort);
            hare = func(hare);
            mu++;
        }
        hare = func (tort);
        int len = 1;
        while (tort != hare)
        {
            hare = func (hare);
            len++;
        }
        cout << "Case " << cases << ": ";
        cout << len << endl;
    }
    return 0;
}