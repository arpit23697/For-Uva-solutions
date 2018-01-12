#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <bits/stdc++.h>
#include <stack>
#include <tuple>
#include <deque>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    long long int n , l , u;
    long long  int ans;
    while (scanf ("%lld %lld %lld",&n , &l , &u) == 3) {
        bitset<32> set1(n);
        ans = 0;

        for (int i = 31; i >= 0; i--) {
            //cout << (1LL << i) << endl;
            if (n & (1LL << i))
            {
                if ((ans + (1LL << i)) <= l)
                    ans += 1LL << i;
            }

            else {
                if ( (ans + (1LL << i)  <= u)) {
                    ans += 1LL << i;
                }
            }
        }
        cout << ans << endl;
    }

    fclose (stdin);
    fclose (stdout);

    return 0;
}