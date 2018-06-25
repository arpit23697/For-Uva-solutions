#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    vector < pair <double , pair <int , int >>  > mySet;
    
    int n , k;
    while (scanf ("%d %d" , &n , &k) == 2)
    {
        mySet.clear();
        for (int first = 1 ; first <= n ; first++)
        {
            for (int second = 1 ; second <= first ; second++)
            {
                if (gcd (first , second ) == 1)
                    mySet.push_back(make_pair (second/(first * 1.0) , make_pair (second ,first) )); 
            }
        }
        sort (mySet.begin() , mySet.end());
        /*for (int i= 0 ; i < mySet.size() ; i++)
        {
            cout << mySet[i].first << " " << mySet[i].second.first  << " " << mySet[i].second.second << endl;
       }*/
        
        
        cout << mySet[k-1].second.first << "/" << mySet[k-1].second.second << endl;
    }
    return 0;
}