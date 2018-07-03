#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    int test ;
    cin >> test;
    int cases =0;
    while (test--)
    {
        cases++;

        string str;
        cin >> str;
        vector <int> freq(26);
        int len = str.length();
        for (int i =0 ; i < len ; i++)
        freq[str[i] - 'A']++;

      //  for (int i= 0 ; i < 26 ; i++)
    //    cout << freq[i] << endl;

        long long int ans = 1;
        for (int i =2; i <= len ; i++)
        ans = ans * i;

        for (int i = 0 ; i < 26 ; i++)
        {
            long long int temp =1;

            if (freq[i] >= 2)
            {
                for (int j = 2 ; j <= freq[i] ; j++)
                temp = temp * j;
            }
            ans = ans / temp;
        }
        cout << "Data set " << cases << ": " << ans << endl; 
    }
    
    
    return 0;
}