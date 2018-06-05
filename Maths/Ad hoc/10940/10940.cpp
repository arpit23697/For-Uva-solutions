#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    while (1)
    {
        int n; 
        cin >> n;
        if (n ==0)
        break;
        
        int ans = 1;
        int temp = 1;
        while (temp < n)
            temp = 2*temp;

        if (temp == n)
        ans = n;
        else
        {
            temp = temp/2;
            ans = 0;
            ans = (n-temp) * 2;
        }


        cout << ans << endl;
    }
        return 0;
}