#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen("in.txt" , "r"  , stdin);
    freopen("out.txt" , "w" , stdout);
    long long int n , m;
    while (scanf ("%lld %lld" , &n, &m) == 2)
    {
        long long int level1 = floor (sqrt (n));
        long long int level2 = floor (sqrt(m));

       // cout << level1 << " " << level2 << "hii \n";
        //this for 1st point
        long long int mean1 = ((pow (level1 ,2 ) + (pow (level1+1 , 2) - 1) )/2);
        long long int mean2 = ((pow (level2 ,2 ) + (pow (level2+1 , 2) - 1) )/2);
        long long int x1 = n - mean1;
        long long int x2 = m - mean2;
    
       // cout << x1 << " " << x2 << " xs \n";
        double hor = ( x2 - x1 ) / 2;
        double vertical = 0;

        double y1 = 0;
        if (level1 == 0)
        y1 = 0;
        
        else
        {
            y1 += (sqrt(3) / 2) * (level1 - 1);
            y1 += 1 / (2 * sqrt(3));

            if (level1 % 2 == 0)
            {
                if (abs(x1)%2 == 0 )
                y1 += 1 / (sqrt(3)); 
                else
                y1 += 1 / (2 * sqrt(3));
            }
            else
            {
                if (abs(x1) % 2 == 0 )
                y1 += 1 / (2 * sqrt(3));
                else
                y1 += 1 / (sqrt(3));
            }
        }
        
        //cout << mean1 << " " << mean2 << " afdfa  \n";        
        double y2 = 0;
        if (level2 == 0)
        y2 = 0;
        else
        {
            y2 += (sqrt(3) / 2) * (level2 - 1);
            y2 += 1 / (2 * sqrt(3));

            if (level2 % 2 == 0)
            {
                if (abs(x2) % 2 == 0 )
                y2 += 1 / (sqrt(3)); 
                else
                y2 += 1 / (2 * sqrt(3));
            }
            else
            {
                if (abs(x2) % 2 == 0 )
                y2 += 1 / (2 * sqrt(3));
                else
                y2 += 1 / (sqrt(3));
            }
        }
      //  cout << y2 << " y2 " << y1 << " y1 " << endl;
      //  cout << "x1 " << x1 << " x2 " << x2 <<endl;
        double ans = pow (y2 - y1 , 2);
      //  cout << ans << endl;
        ans += pow ( ((x2 - x1) * 1.0 )/ 2 , 2);
        ans = sqrt(ans);  
        printf("%.3lf\n", ans);
    }

    return 0;
}