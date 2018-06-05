    #include <bits/stdc++.h>
    using namespace std;

    int main ()
    {
        freopen ("in.txt" , "r" , stdin);
        freopen ("out.txt" , "w" , stdout);
        int test;
        cin >> test;
        int cases = 0;
        while (test--)
        {
            cases++;
            long long int u , v , d;
            cin >>d >> v >> u;
            if (u > v && v != 0)
            {
                double t1 , t2;
                t1 = d/(u*1.0);
                t2 = (d*1.0)/ sqrt (u*u - v*v);
                double ans = t2 - t1;
                printf ("Case %d: %.3lf\n", cases  , ans);
            }
            else
            printf ("Case %d: can't determine\n", cases);
        }

        return 0;
    }