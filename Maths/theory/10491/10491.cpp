#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("in.txt" , "r" ,stdin);
    freopen ("out.txt" , "w" , stdout);
    double ncows , ncars , nshow;
    while (scanf ("%lf %lf %lf", &ncows , &ncars , &nshow) == 3)
    {
        double ans = (ncows / (ncows + ncars)) * ( ncars / (ncars + ncows - nshow - 1));
        ans += (ncars / (ncows + ncars)) * ( (ncars -1)  / (ncars + ncows - nshow - 1));
        printf("%.5f\n" , ans );
    }
    return 0;
}