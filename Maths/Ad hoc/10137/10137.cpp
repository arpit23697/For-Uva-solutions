#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("in.txt" , "r" ,stdin);
    freopen ("out.txt" , "w" , stdout);
    while (1)
    {
        int n;
        cin >> n;

        if (n == 0)
        break;
        double array[n];
        double avg = 0;
        for (int i = 0 ; i < n ; i++)
        {

            cin >> array[i];
            array[i] *= 100;
            avg += array[i];
        }

        int avg2 = floor (avg / n);
        int avg3 = ceil (avg / n);
        double ans1 = 0;
        double ans2 = 0;
        //cout << avg2 << endl;
        for (int i= 0 ; i < n ; i++)
        {
            if (array[i] > avg3)
            ans1 += (array[i] - avg3);
            else if (array[i] < avg2)
            ans2 += (avg2- array[i]) ;
        }
        double m = (max (ans1 , ans2) * 1.0) / 100 ;
        printf("$%.2lf\n", m);
    }
    
    
    return 0;
}