#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test;
    cin >> test;

    while (test--)
    {

        long long int n;
        vector <int> ans(10);
        cin >> n;
        
        for (int i= 1 ; i <= n ; i++)
        {
            long long int temp = i;
            int x;
            while (temp != 0)
            {
                x = temp%10;
                ans[x]++;
                temp = temp/10;
            }
        }
        cout << ans[0];
        for (int i=1 ; i < 10 ; i++)
        cout << " " << ans[i];
        cout <<endl;
       
    }

    return 0;
}