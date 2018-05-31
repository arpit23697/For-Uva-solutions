#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    int test;
    cin >> test;
    //cin.ignore ('\n');
    //cin.ignore('\n');

    while (test--)
    {
        double dist = 0;
        int x , y;
        scanf("%d %d\n",&x , &y);
     //   cout << x << "-----------" << y << endl;
        
        string line;
        while (getline (cin , line))
        {
       //     cout << line << endl;
            if (line.empty())
            break;

        
            istringstream is(line);
            int x1 , x2 , y1 , y2;
            is >> x1 >> y1 >> x2>> y2;
            dist += 2 *sqrt(pow ( (x2 - x1) , 2) + pow ((y2 - y1) , 2));
            //cout << dist << endl;
        }

       // cout << dist << endl;
        double time = (dist *3)/1000;
       // cout << time << endl;
        int actualTime = round (time);
       // cout << actualTime << endl;

        int hours = actualTime / 60;
        int mini = actualTime % 60;
        cout << hours << ":";
        if (mini < 10)
        cout << "0" << mini << endl;
        else
        cout << mini << endl;
        if (test > 0)
        cout << endl;
    }
    return 0;
}
