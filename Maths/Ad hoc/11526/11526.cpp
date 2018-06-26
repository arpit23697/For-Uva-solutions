#include <bits/stdc++.h>
using namespace std;

//'-1' means no carry 

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
        int n;
        cin >> n;
        int temp;
        vector <int> freq;
        freq.assign (101 , 0);
        for (int i= 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++)
        {
            cin >> temp;
            freq[temp]++;
        }
        bool ans = true;
        for (int i = 0; i <= 100 ; i++)
        {
            if (freq[i] > n)
            {
                ans = false;
                break;
            }
        }
        cout << "Case " << cases << ": ";
        if (ans)
        cout << "yes" << endl;
        else 
        cout << "no" << endl;
    }

}