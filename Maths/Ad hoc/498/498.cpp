#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    string str;
    while (getline (cin , str))
    {
    //    cout << str << endl;    
        istringstream s(str);
        vector <int> coef;
        int temp;
        while (s >> temp)
        coef.push_back(temp);

      //  for (int i =0 ; i < coef.size() ; i++)
      //  cout << coef[i] << " " ;
      //  cout << endl << endl;


        getline (cin , str);
        istringstream s2(str);
        vector <int> x;
        while (s2 >> temp)
        x.push_back(temp);
 // for (int i =0 ; i < x.size() ; i++)
   //     cout << x[i] << " " ;
     //   cout << endl << endl;

        int n = coef.size();
        bool first = true;
        for (int i = 0 ; i < x.size() ; i++)
        {   
            long long int ans = 0;
            for (int j = n-1 ; j >= 0 ;j-- )
            ans += coef[j] * pow (x[i] , n-1 - j);
            if (first)
            {
            first = false;
            cout << ans;
            }
            else
            cout << " " << ans;
        }
        cout << endl;
    
    }
        
    return 0;
}