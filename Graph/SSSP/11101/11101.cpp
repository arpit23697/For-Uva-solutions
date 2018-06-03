#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);

    while (1)
    {
        int p;
        cin >> p;
        if (p == 0 )
        break;

        int x , y , xmax , xmin , ymax , ymin ;
        vector <pair <int , int >> A , B , C;
        cin >> x >> y;
        xmax = x;
        xmin = x;
        ymax = y;
        ymin = y;
        A.push_back(make_pair(x, y));
        for (int i =0 ; i < p-1 ; i++)
        {
            cin >> x >> y;
            xmax = max (x , xmax);
            xmin = min (x , xmin);
            ymax = max (y , ymax);
            ymin = min (y , ymin);
            A.push_back(make_pair(x, y));
        }

        for (int i =0 ; i < p ; i++)
        {
            if (A[i].first == xmax || A[i].first == xmin || A[i].second == ymax || A[i].second == ymin)
                C.push_back(A[i]);
        }

        int p1;
        cin >> p1;
        int n = C.size();
        for (int i= 0; i < p1 ; i++)
        {
            cin >> x >> y;
            B.push_back(make_pair(x, y));
        }
        int ans = abs (A[0].first - B[0].first) + abs (A[0].second - B[0].second);  
        for (int i= 0 ; i < n ; i++)
        {
            for (int j =0 ; j < p1 ; j++)
                ans = min(ans, abs(C[i].first - B[j].first) + abs(C[i].second - B[j].second));
        }
        cout << ans << endl;
    }
    return 0;
}