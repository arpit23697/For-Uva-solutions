#include <bits/stdc++.h>
using namespace std;

double degreeTo (int degree)
{
    return degree * 3.141592653589793 / 180.0;
}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    
    while (1)
    {
       long long int a , b , v , angle , times;
       cin >> a >> b >> v >> angle >> times;

       if ((a || b || v || times || angle) == 0)
       break;

       

       double totalDistance = (times * v) / 2.0;
       long long int  horizontal =0 , vertical = 0 ;
       double x , y;
       x = (a*1.0)/2;
       y = (b*1.0) / 2;
       long long int final_x , final_y;
       
       final_x = ceil (x + totalDistance * cos(degreeTo(angle))) ;
       final_y = ceil (y + totalDistance * sin (degreeTo (angle)) ) ;

       if (final_x % a == 0)
       vertical = final_x / a - 1;
       else
       vertical = final_x / a;
       if (final_y % b == 0)
       horizontal = final_y / b - 1 ;
       else
       horizontal = final_y / b;

     //  cout << final_x << " " << final_y << endl;
       printf ("%lld %lld\n" , vertical , horizontal);
    }
    return 0;
}

//  double temp_x , temp_y;
//cout << totalDistance << endl;
/*   while (totalDistance > 0)
       {
           temp_x = x + (b-y) * tan (degreeTo (90 - angle));
           temp_y = y + (a-x) * tan (degreeTo (angle));
         
 

           //cout << temp_x << " " << temp_y << endl;
           if (temp_x <= a && temp_x >= 0 && temp_y <= b && temp_y >= 0)
           {
               totalDistance -= sqrt(pow(abs(temp_x - x), 2) + pow(abs(temp_y - y), 2));
               if (totalDistance < 0)
               break;
               vertical += 1;
               horizontal += 1;
               angle = 180 + angle;
            }

                else if (temp_x <= a && temp_x >= 0)
                {
                   
                    if (temp_y >= b)
                        temp_y = b;
                    else
                        temp_y = 0;
                    totalDistance -= sqrt(pow(abs(temp_x - x), 2) + pow(abs(temp_y - y), 2));
                    if (totalDistance < 0)
                        break;
                    horizontal += 1;
                    angle = 360 - angle;
                }
            else if (temp_y <= b && temp_y >= 0)
            {
            
                if (temp_x >= a)
                    temp_x = a;
                else
                    temp_x = 0;
                totalDistance -= sqrt(pow(abs(temp_x - x), 2) + pow(abs(temp_y - y), 2));
                if (totalDistance < 0)
                    break;
                    vertical+=1;
                angle = 180 - angle;
           }

           
           x = temp_x;
           y = temp_y;
           cout << x << " " << y << " " << totalDistance << endl;
       }*/